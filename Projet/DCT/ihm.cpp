#include "ihm.h"
#include "ui_ihm.h"

IHM::IHM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM)
{
    ui->setupUi(this);

    /* Information générale */
    ui->labelVersion->setText(QDate::currentDate().toString());
    this->setWindowTitle("Application DCT");

    /* Zone Bouton */
    connect(ui->pushButtonStart, SIGNAL(clicked(bool)), this, SLOT(startClick()));
    connect(ui->pushButtonClear,SIGNAL(clicked(bool)),this,SLOT(clearClick()));
    connect(ui->pushButtonFocus,SIGNAL(clicked(bool)),this,SLOT(focusClick()));

    /* Zone Menu */
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openFileClick()));
    connect(ui->actionSave,SIGNAL(triggered(bool)),this,SLOT(saveFileClick()));

    connect(ui->actionAbout,SIGNAL(triggered(bool)),this,SLOT(aboutClick()));

    connect(&DataCalc,SIGNAL(progressionSignal(int)),this,SLOT(updateProgressBar(int)));

    /* Ajout des graph */
    ui->graphCurve->addGraph();
    ui->graphTransf->addGraph();

    /* Couleur des tracés */
    ui->graphCurve->graph()->setPen(QPen(Qt::blue));
    ui->graphTransf->graph()->setPen(QPen(Qt::red));

    /* Nom des labels */
    ui->graphCurve->xAxis->setLabel("x");
    ui->graphCurve->yAxis->setLabel("Signal d'entrée");

    ui->graphTransf->xAxis->setLabel("x");
    ui->graphTransf->yAxis->setLabel("Transformée");

    ui->progressBar->setFormat("%p% effectué (%v sur %m)");
    ui->progressBar->setValue(0);
}

IHM::~IHM()
{
    dataInX.clear();
    dataInY.clear();
    dataOutX.clear();
    dataOutY.clear();

    delete ui;
}


void IHM::updateGraph(void)
{
    //updateInSection();
    //updateOutSection(); 

    ui->graphCurve->rescaleAxes(true);
    ui->graphTransf->rescaleAxes(true);

    ui->graphCurve->replot();
    ui->graphTransf->replot();

    ui->progressBar->setValue(0);
    ui->progressBar->update();
}


void IHM::openDialogBox(QString title,QString txt)
{
    msgBox.setTitle(title);
    msgBox.setInfo(txt);

    msgBox.updateDialogBox();

    /* On affiche la fênetre */
    msgBox.show();

    /* On empêche l'utilisateur d'agir sur la fenetre principale
     * en forçant le focus sur la fenetre de dialog
     * appui sur cancel/continue olbigatoire */
    msgBox.setVisible(FALSE);

    msgBox.exec();
}

void IHM::updateInSection(QString fileName,QString type,int duration,int size)
{
    QString tmp;
    QString txt;

    ui->labelIn->clear();

    txt += "Name :\n";
    txt += fileName +"\n";
    txt += "Type :\n";
    txt += type +"\n";
    txt += "Duration :\n";
    txt += tmp.setNum(duration)+" ms"+"\n";
    txt += "Size :\n";
    txt += tmp.setNum(size)+" octet(s)"+"\n";

    ui->labelIn->setText(txt);
}

void IHM::updateOutSection(QString transformName,int time)
{
    QString tmp;
    QString txt;

    ui->labelOut->clear();

    txt += "Operation :\n";
    txt += transformName+"\n";
    txt += "Calculation time :\n";
    txt += tmp.setNum(time)+" ms"+"\n";

    ui->labelOut->setText(txt);
}

void IHM::enableAllCmd(void)
{
    ui->pushButtonStart->setEnabled(true);
    ui->pushButtonFocus->setEnabled(true);
    ui->pushButtonClear->setEnabled(true);

    ui->menuBar->setEnabled(true);
}

void IHM::disableAllCmd(void)
{
    ui->pushButtonStart->setEnabled(false);
    ui->pushButtonFocus->setEnabled(false);
    ui->pushButtonClear->setEnabled(false);

    ui->menuBar->setEnabled(false);
}

/*************************************** SLOTS *****************************************/
/***************************************************************************************/


void IHM::startClick(void)
{
    QTime tps;

    tps.start();
    disableAllCmd();
    ui->progressBar->setRange(0, dataInX.size());

    /* On démarre la transformée choisie */;
    if(ui->radioButtonDCT->isChecked() == true)
    {
        DataCalc.dctTransform(dataInX,dataInY,dataOutX,dataOutY);
        updateOutSection("DCT",tps.elapsed());
    }
    else
    {
        DataCalc.idctTransform(dataInX,dataInY,dataOutX,dataOutY);
        updateOutSection("IDCT",tps.elapsed());
    }

    /* On affiche les résultats */
    ui->graphCurve->graph(0)->setData(dataInX,dataInY); // data
    ui->graphCurve->axisRect()->setupFullAxesBox(true);
    ui->graphCurve->rescaleAxes(true); // ajustement auto des axes
    ui->graphCurve->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); // autorisation des zooms avec la souris/mollette

    ui->graphTransf->graph(0)->setData(dataOutX,dataOutY);
    ui->graphTransf->axisRect()->setupFullAxesBox(true);
    ui->graphTransf->rescaleAxes(true);
    ui->graphTransf->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    /* On actualise l'affichage */
    updateGraph();
    enableAllCmd();
}

void IHM::clearClick(void)
{
    /* Effacement des donnees des graphs */
    ui->graphCurve->graph(0)->clearData();
    ui->graphTransf->graph(0)->clearData();

    /* Update */
    updateGraph();
}

void IHM::focusClick(void)
{
    /* Update */
    updateGraph();
}

void IHM::openFileClick(void)
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Texte (*.txt);;CSV(*.csv);;Son(*.wav)"));
    string type;

    if(fileName != "\0")
    {
        type = fileName.toStdString().substr(fileName.indexOf("."));

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
            pDataSignal->ReadData(fileName,dataInX,dataInY);
            delete[]pDataSignal;
        }
    }
}


void IHM::saveFileClick(void)
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),"",tr("Texte (*.txt);;CSV(*.csv);;Son(*.wav)"));
    string type;

    if(fileName != "\0")
    {
        type = fileName.toStdString().substr(fileName.indexOf("."));

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
    QString title,txt;

    title = "Information";

    txt = "Application DCT/IDCT\n\n";
    txt += "écrite par :\n";
    txt += "\t- Chloé PAGES\n";
    txt += "\t- Dan SOULLAMA\n";
    txt += "\t- Nicolas JULLIEN\n";
    txt += "\t- Julien GUICHON\n";
    txt += "\n";
    txt += "INSA GEA 2014-2017";

    openDialogBox(title,txt);
}

void IHM::updateProgressBar(int value)
{
    ui->progressBar->setValue(value);
    ui->progressBar->update();
}
