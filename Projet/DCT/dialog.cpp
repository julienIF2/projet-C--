/*************************************** INCLUDE ***************************************/
/***************************************************************************************/
#include <QIcon>

#include "dialog.h"
#include "ui_dialog.h"

/*************************************** CODE    ***************************************/
/***************************************************************************************/

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    /* Initialisation */
    titleString = "None";
    infoString = "None";
    flagError = false;

    /* Connections */
    connect(ui->pushButtonDialogCancel,SIGNAL(clicked(bool)),this,SLOT(cancelClick()));
    connect(ui->pushButtonDialogContinue,SIGNAL(clicked(bool)),this,SLOT(continueClick()));

    /* Update */
    updateDialogBox();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::cancelClick(void)
{
    /* Todo : renvoyer le signal à mainwWindow */
    close();
}

void Dialog::continueClick(void)
{
    /* Todo : renvoyer le signal à mainwWindow*/
    close();
}

void Dialog::updateDialogBox(void)
{
    this->setWindowTitle(titleString);
    ui->labelDialogInfo->setText(infoString);

    if(flagError == true)
    {
        ui->pushButtonDialogContinue->setEnabled(false);
        ui->pushButtonDialogContinue->setDisabled(true);
    }
    else
    {
        ui->pushButtonDialogContinue->setEnabled(true);
        ui->pushButtonDialogContinue->setDisabled(false);
    }
    ui->pushButtonDialogContinue->update();
}

void Dialog::setTitle(QString title)
{
    titleString = title;
}

void Dialog::setInfo(QString info)
{
    infoString = info;
}

