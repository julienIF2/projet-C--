#include "qihm.h"
#include "ui_qihm.h"

QIHM::QIHM(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QIHM)
{
    ui->setupUi(this);
}

QIHM::~QIHM()
{
    delete ui;
}
