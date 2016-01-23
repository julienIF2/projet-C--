#include "ihm.h"
#include "ui_ihm.h"

IHM::IHM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IHM)
{
    ui->setupUi(this);

    /* Information générale */
    ui->labelVersion->setText("V0.0 04/10/2015");
    this->setWindowTitle("Application DCT");

    /* Zone Bouton */
    connect(ui->pushButtonStart, SIGNAL(clicked(bool)), this, SLOT(startClick()));
    connect(ui->pushButtonClear,SIGNAL(clicked(bool)),this,SLOT(clearClick()));
    connect(ui->pushButtonFocus,SIGNAL(clicked(bool)),this,SLOT(focusClick()));


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



    // TODO suppr
    DataSignal.ReadData("testSinus.wav");

}

IHM::~IHM()
{
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
}


/*************************************** SLOTS *****************************************/
/***************************************************************************************/


void IHM::startClick(void)
{
    QVector<double> x1,y1,x2,y2;


    /* On récupère les données d'entré */
    DataSignal.GetData(x1,y1);
    DataCalc.SetData(x1,y1);

    /* On démarre la transformée choisie */
    // TODO choix transformée
    DataCalc.startDCT();

    /* On récupère le résultat */
    DataCalc.GetData(x2,y2);

    /* On affiche les résultats */
    ui->graphCurve->graph(0)->setData(x1,y1); // data
    ui->graphCurve->axisRect()->setupFullAxesBox(true);
    ui->graphCurve->rescaleAxes(true); // ajustement auto des axes
    ui->graphCurve->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); // autorisation des zooms avec la souris/mollette

    ui->graphTransf->graph(0)->setData(x2,y2);
    ui->graphTransf->axisRect()->setupFullAxesBox(true);
    ui->graphTransf->rescaleAxes(true);
    ui->graphTransf->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    /* On free */
    x1.clear();
    y1.clear();
    x2.clear();
    y2.clear();

    /* On actualise l'affichage */
    updateGraph();
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
