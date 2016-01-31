#include "ihm.h"
#include "ui_ihm.h"

IHM::IHM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM)
{
    ui->setupUi(this);

    /* Information générale */
    this->setWindowTitle("Application DCT");


    /* Connection Bouton */
    connect(ui->pushButtonStart, SIGNAL(clicked(bool)), this, SLOT(startClick()));
    connect(ui->pushButtonClear,SIGNAL(clicked(bool)),this,SLOT(clearClick()));
    connect(ui->pushButtonFocus,SIGNAL(clicked(bool)),this,SLOT(focusClick()));

    /* Connection Menu */
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openFileClick()));
    connect(ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(saveFileClick()));
    connect(ui->actionAbout,SIGNAL(triggered(bool)),this,SLOT(aboutClick()));

    /* Connection barre de progression */
    connect(&DataCalc,SIGNAL(progressionSignal(int)),this,SLOT(updateProgressBar(int)));

    /* Connection modification signal */
    connect(ui->enableSignalWindow,SIGNAL(toggled(bool)),this,SLOT(toogleBoxSignalWindow()));
    connect(ui->enableCalcWindow,SIGNAL(toggled(bool)),this,SLOT(toogleBoxCalcWindow()));
    connect(ui->pushButtonWindowing,SIGNAL(clicked(bool)), this, SLOT(signalWindow()));


    /* Graph */
    ui->graphCurve->addGraph();                         // ajout des graphs
    ui->graphTransf->addGraph();
    ui->graphCurve->graph()->setPen(QPen(Qt::blue));    // couleurs graphs
    ui->graphTransf->graph()->setPen(QPen(Qt::red));
    ui->graphCurve->xAxis->setLabel("x");               // Labels des graphs
    ui->graphCurve->yAxis->setLabel("Signal d'entrée");
    ui->graphTransf->xAxis->setLabel("x");
    ui->graphTransf->yAxis->setLabel("Transformée");

    /* Barre de progression */
    ui->progressBar->setFormat("%p% effectué (%v sur %m)"); // format barre de progression
    ui->progressBar->setValue(0);

    /* Initialisation des items */
    ui->enableSignalWindow->setChecked(false);
    ui->enableCalcWindow->setChecked(false);
    ui->timeEditStart->setEnabled(false);
    ui->timeEditStop->setEnabled(false);
    ui->pushButtonWindowing->setEnabled(false);
    ui->spinBoxCalcWindow->setEnabled(false);
    ui->spinBoxCalcWindow->setMaximum(0);
    ui->spinBoxCalcWindow->setMinimum(0);

    /* Initialisation du choix des fenêtres */
    QStringList windowList;
    DataCalc.getWindowsType(windowList);                // Récupération des différentes fenêtres
    ui->comboBoxCalcWindow->addItems(windowList);
    ui->comboBoxCalcWindow->setEnabled(false);
}

IHM::~IHM()
{
    /* Désallocation de la mémoire */
    dataInX.clear();
    dataInY.clear();
    dataOutX.clear();
    dataOutY.clear();

    delete ui;
}


void IHM::updateGraph(void)
{
    ui->graphCurve->rescaleAxes(true);      //  Réajustement des axes activé
    ui->graphTransf->rescaleAxes(true);

    ui->graphCurve->replot();               // Affichage des graphs
    ui->graphTransf->replot();

    ui->progressBar->setValue(0);           // Reset de la barre de progression
    ui->progressBar->update();
}

void IHM::updateInSection(QString fileName,QString type,long duration,long size,long nbSample)
{
    QString tmp;
    QString txt;
    QTime time(0,0);

    ui->labelIn->clear();       // reset de l'affichage

    //qDebug() << duration;

    time = time.addSecs(duration/1000);     // calcul du temps
    time = time.addMSecs(duration%1000);

    //qDebug() << time.toString();

    txt += "Name :\n";
    txt += fileName +"\n";
    txt += "Type :\n";
    txt += type +"\n";
    txt += "Duration :\n";
    txt += time.toString("mm:ss:zzz")+"\n";
    txt += "Size :\n";
    txt += tmp.setNum(size/1000)+" ko"+"\n";
    txt += "nb.Sample(s) :\n";
    txt += tmp.setNum(nbSample)+"\n";

    ui->labelIn->setText(txt);          // chargement des informations du fichier
}

void IHM::updateOutSection(QString transformName,int time)
{
    QString tmp;
    QString txt;

    ui->labelOut->clear();  // reset de l'affichage

    txt += "Operation :\n";
    txt += transformName+"\n";
    txt += "Calculation time :\n";
    txt += tmp.setNum(time)+" ms"+"\n";

    ui->labelOut->setText(txt);          // chargement des informations du fichier
}

void IHM::enableAllCmd(void)
{
    /* Réactivation de toutes les commandes */
    ui->pushButtonStart->setEnabled(true);
    ui->pushButtonFocus->setEnabled(true);
    ui->pushButtonClear->setEnabled(true);

    ui->menuBar->setEnabled(true);
    ui->menuBar->update();

    if(ui->enableSignalWindow->isChecked())
    {
        ui->pushButtonWindowing->setEnabled(true);
    }
}


void IHM::disableAllCmd(void)
{
    /* Désactivation de toutes les commandes */
    ui->pushButtonStart->setEnabled(false);
    ui->pushButtonFocus->setEnabled(false);
    ui->pushButtonClear->setEnabled(false);

    ui->menuBar->setEnabled(false);

    ui->pushButtonWindowing->setEnabled(false);
}

/*************************************** SLOTS *****************************************/
/***************************************************************************************/


void IHM::startClick(void)
{
    QTime tps;
    QString windowType;
    unsigned long windowSize;
    /* Start du timer pour le tps de calcul */
    tps.start();

    /* On désactive les actions de l'utilisateur */
    disableAllCmd();

    /* Actualisation de la plage (barre de progression) */
    ui->progressBar->setRange(0, dataInX.size());



    /* Test du choix de fenêtrage */
    windowSize =  ui->spinBoxCalcWindow->value();

    if((ui->enableCalcWindow->isChecked()==TRUE) & (windowSize > 0)) // activé
    {

        windowType = ui->comboBoxCalcWindow->currentText();
    }
    else                                                             // désactivé
    {
        windowType = "\0";
        windowSize = dataInX.size();
    }


    /* On exéctue la transformé choisie */
    if(ui->radioButtonDCT->isChecked() == true) // DCT
    {
        DataCalc.dctTransform(dataInX,dataInY,dataOutX,dataOutY,windowType,windowSize);
        updateOutSection("DCT",tps.elapsed());
    }
    else                                        // IDCT
    {
        DataCalc.idctTransform(dataInX,dataInY,dataOutX,dataOutY,windowType,windowSize);
        updateOutSection("IDCT",tps.elapsed());
    }


    /* Chargement des résultats */
    ui->graphCurve->graph(0)->setData(dataInX,dataInY); // data
    ui->graphCurve->axisRect()->setupFullAxesBox(true);
    ui->graphCurve->rescaleAxes(true); // ajustement auto des axes
    ui->graphCurve->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); // autorisation des zooms avec la souris/mollette


    ui->graphTransf->graph(0)->setData(dataOutX,dataOutY);
    ui->graphTransf->axisRect()->setupFullAxesBox(true);
    ui->graphTransf->rescaleAxes(true);
    ui->graphTransf->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    /* Actualisation de l'affichage */
    updateGraph();

    /* Réactivation des commandes */
    enableAllCmd();
}

void IHM::clearClick(void)
{
    /* Effacement des donnees des graphs */
    ui->graphCurve->graph(0)->clearData();
    ui->graphTransf->graph(0)->clearData();

    /* Mise à jour graph */
    updateGraph();
}

void IHM::focusClick(void)
{
    /* Mise à jour graph */
    updateGraph();
}


void IHM::openFileClick(void)
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("CSV (*.csv);;Texte (*.txt);;Son (*.wav)"));
    string type;
    Signaux::fileInfoStruct info;

    if(fileName != "\0")
    {
        type = fileName.toStdString().substr(fileName.indexOf(".")); //  récupère le type du fichier

        pDataSignal = NULL;
        if(type == ".csv")
        {
            pDataSignal = new signalCSV;
        }
        else if(type == ".txt")
        {
            pDataSignal = new signalTXT;
        }
        else if(type == ".wav")
        {
            pDataSignal = new signalWAV;
        }
        else
        {
            qDebug() << "erreur type fichier";
        }


        if(pDataSignal != NULL) // si pas d'erreur sur le fichier
        {
            pDataSignal->ReadInfo(fileName,&info);              // lecture des info
            pDataSignal->ReadData(fileName,dataInX,dataInY);    // lecture des data
            delete[]pDataSignal;                                // on dessalloue le pointeur

            updateInSection(info.fileName,info.fileType,info.fileDuration,info.fileSize,info.nbSample); // mise à jour des info

            ui->spinBoxCalcWindow->setMaximum(dataInX.size());  // Mise à jour de la range du fenêtrage
            ui->spinBoxCalcWindow->setMinimum(0);

            /* On affiche les résultats */
            ui->graphCurve->graph(0)->setData(dataInX,dataInY); // data
            ui->graphCurve->axisRect()->setupFullAxesBox(true);
            ui->graphCurve->rescaleAxes(true); // ajustement auto des axes
            ui->graphCurve->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); // autorisation des zooms avec la souris/mollette
        }
    }

    /* Update */
    updateGraph();
}


void IHM::saveFileClick(void)
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"",tr("Texte (*.txt);;CSV(*.csv);;Son(*.wav)"));
    string type;

    if(fileName != "\0")
    {
        type = fileName.toStdString().substr(fileName.indexOf(".")); //  récupère le type du fichier

        pDataSignal = NULL;
        if(type == ".csv")
        {
            pDataSignal = new signalCSV;
        }
        else if(type == ".txt")
        {
            pDataSignal = new signalTXT;
        }
        else if(type == ".wav")
        {
            pDataSignal = new signalWAV;
        }
        else
        {
            qDebug() << "erreur type fichier";
        }


        if(pDataSignal != NULL)
        {
            pDataSignal->SaveData(fileName,dataOutX,dataOutY);
            delete[]pDataSignal;
        }
    }
}

void IHM::aboutClick(void)
{
    QString txt;

    txt = "Application DCT/IDCT\n\n";
    txt += "écrite par :\n";
    txt += "\t- Chloé PAGES\n";
    txt += "\t- Dan SOULLAMA\n";
    txt += "\t- Nicolas JULLIEN\n";
    txt += "\t- Julien GUICHON\n";
    txt += "\n";
    txt += "INSA GEA 2014-2017";

    QMessageBox::information(this,"Information",txt);
}

void IHM::updateProgressBar(int value)
{
    ui->progressBar->setValue(value);
    ui->progressBar->update();
}

void IHM::toogleBoxSignalWindow(void)
{
    /* Activation/désactivation */
    if(ui->enableSignalWindow->isChecked())
    {
        ui->timeEditStart->setEnabled(true);
        ui->timeEditStop->setEnabled(true);
        ui->pushButtonWindowing->setEnabled(true);
    }
    else
    {
        ui->timeEditStart->setEnabled(false);
        ui->timeEditStop->setEnabled(false);
        ui->pushButtonWindowing->setEnabled(false);
    }
}

void IHM::toogleBoxCalcWindow(void)
{
    /* Activation/désactivation */
    if(ui->enableCalcWindow->isChecked())
    {
        ui->spinBoxCalcWindow->setEnabled(true);
        ui->comboBoxCalcWindow->setEnabled(true);
    }
    else
    {
        ui->spinBoxCalcWindow->setEnabled(false);
    }
}


void IHM::signalWindow(void)
{
    double deltaT;
    double startNum,stopNum;

    if(dataInX.size() >= 2)
    {
        deltaT = dataInX[2]-dataInX[1];

        /* Récupération de la portion de signal */
        startNum = 60000*ui->timeEditStart->time().minute()+1000*ui->timeEditStart->time().second()+ui->timeEditStart->time().msec();
        stopNum = 60000*ui->timeEditStop->time().minute()+1000*ui->timeEditStop->time().second()+ui->timeEditStop->time().msec();

        /* Conversion temps <-> numéro d'échantillion */
        startNum /= deltaT*1000;
        stopNum /= deltaT*1000;

        if((stopNum > startNum)&(stopNum <= dataInX.size()))
        {
            long nbrToSupprBefore = startNum-1;
            long nbrToSupprAfter = dataInX.size()-stopNum;

            /* On supprime les portions inutiles */
            /* Portion supérieure */
            for(long i=1;i<nbrToSupprAfter;i++)
            {
                dataInX.pop_back();
                dataInY.pop_back();
            }

            /* Portion inférieure */
            for(long i=0;i<nbrToSupprBefore;i++)
            {
                dataInX.pop_front();
                dataInY.pop_front();
            }

            /* On met à jours les data */
            ui->graphCurve->graph(0)->setData(dataInX,dataInY); // data
            updateGraph();
        }
        else
        {
            qDebug() << "erreur windowing : start stop";
            qDebug() << "startNum : " << startNum;
            qDebug() << "stopNum :" << stopNum;
            qDebug() << "data size : " << dataInX.size();
        }
    }
    else
    {
        qDebug() << "erreur windowing : dataSize" <<endl;
        qDebug() << "data size : " << dataInX.size();
    }
}
