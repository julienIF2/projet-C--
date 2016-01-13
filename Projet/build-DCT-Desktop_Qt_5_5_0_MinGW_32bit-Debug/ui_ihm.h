/********************************************************************************
** Form generated from reading UI file 'ihm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHM_H
#define UI_IHM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_IHM
{
public:
    QAction *actionSave;
    QAction *actionFermer;
    QAction *actionExit;
    QAction *actionWave;
    QAction *actionTexte;
    QAction *actionHelpMe;
    QAction *actionAbout;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayoutTransf;
    QGroupBox *groupBoxTransf;
    QRadioButton *radioButtonDCT;
    QRadioButton *radioButtonIDCT;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayoutTime;
    QGroupBox *groupBoxTime;
    QTimeEdit *timeEditStart;
    QTimeEdit *timeEditStop;
    QLabel *labelStartTime;
    QLabel *labelStopTime;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutAction;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonFocus;
    QScrollBar *horizontalScrollBar;
    QCustomPlot *graphCurve;
    QCustomPlot *graphTransf;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayoutInput;
    QGroupBox *groupBoxInput;
    QLabel *labelIn;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayoutOuput;
    QGroupBox *groupBoxOutput;
    QLabel *labelOut;
    QLabel *labelVersion;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen;
    QMenu *menuFichier;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IHM)
    {
        if (IHM->objectName().isEmpty())
            IHM->setObjectName(QStringLiteral("IHM"));
        IHM->resize(881, 573);
        IHM->setAcceptDrops(false);
        actionSave = new QAction(IHM);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        actionFermer = new QAction(IHM);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        actionFermer->setEnabled(false);
        actionExit = new QAction(IHM);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setEnabled(true);
        actionWave = new QAction(IHM);
        actionWave->setObjectName(QStringLiteral("actionWave"));
        actionTexte = new QAction(IHM);
        actionTexte->setObjectName(QStringLiteral("actionTexte"));
        actionHelpMe = new QAction(IHM);
        actionHelpMe->setObjectName(QStringLiteral("actionHelpMe"));
        actionAbout = new QAction(IHM);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(IHM);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 181, 141));
        gridLayoutTransf = new QGridLayout(gridLayoutWidget);
        gridLayoutTransf->setSpacing(6);
        gridLayoutTransf->setContentsMargins(11, 11, 11, 11);
        gridLayoutTransf->setObjectName(QStringLiteral("gridLayoutTransf"));
        gridLayoutTransf->setContentsMargins(0, 0, 0, 0);
        groupBoxTransf = new QGroupBox(gridLayoutWidget);
        groupBoxTransf->setObjectName(QStringLiteral("groupBoxTransf"));
        radioButtonDCT = new QRadioButton(groupBoxTransf);
        radioButtonDCT->setObjectName(QStringLiteral("radioButtonDCT"));
        radioButtonDCT->setGeometry(QRect(20, 40, 95, 20));
        radioButtonDCT->setChecked(true);
        radioButtonIDCT = new QRadioButton(groupBoxTransf);
        radioButtonIDCT->setObjectName(QStringLiteral("radioButtonIDCT"));
        radioButtonIDCT->setGeometry(QRect(20, 90, 95, 20));

        gridLayoutTransf->addWidget(groupBoxTransf, 0, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 160, 181, 201));
        gridLayoutTime = new QGridLayout(gridLayoutWidget_2);
        gridLayoutTime->setSpacing(6);
        gridLayoutTime->setContentsMargins(11, 11, 11, 11);
        gridLayoutTime->setObjectName(QStringLiteral("gridLayoutTime"));
        gridLayoutTime->setContentsMargins(0, 0, 0, 0);
        groupBoxTime = new QGroupBox(gridLayoutWidget_2);
        groupBoxTime->setObjectName(QStringLiteral("groupBoxTime"));
        groupBoxTime->setEnabled(true);
        timeEditStart = new QTimeEdit(groupBoxTime);
        timeEditStart->setObjectName(QStringLiteral("timeEditStart"));
        timeEditStart->setGeometry(QRect(30, 60, 118, 22));
        timeEditStart->setCurrentSection(QDateTimeEdit::MinuteSection);
        timeEditStop = new QTimeEdit(groupBoxTime);
        timeEditStop->setObjectName(QStringLiteral("timeEditStop"));
        timeEditStop->setGeometry(QRect(30, 130, 118, 22));
        labelStartTime = new QLabel(groupBoxTime);
        labelStartTime->setObjectName(QStringLiteral("labelStartTime"));
        labelStartTime->setGeometry(QRect(20, 30, 121, 16));
        labelStopTime = new QLabel(groupBoxTime);
        labelStopTime->setObjectName(QStringLiteral("labelStopTime"));
        labelStopTime->setGeometry(QRect(20, 100, 121, 16));
        label = new QLabel(groupBoxTime);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 160, 131, 16));

        gridLayoutTime->addWidget(groupBoxTime, 0, 0, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 369, 181, 151));
        verticalLayoutAction = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutAction->setSpacing(6);
        verticalLayoutAction->setContentsMargins(11, 11, 11, 11);
        verticalLayoutAction->setObjectName(QStringLiteral("verticalLayoutAction"));
        verticalLayoutAction->setContentsMargins(0, 0, 0, 0);
        pushButtonStart = new QPushButton(verticalLayoutWidget);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));

        verticalLayoutAction->addWidget(pushButtonStart);

        pushButtonClear = new QPushButton(verticalLayoutWidget);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));
        pushButtonClear->setEnabled(true);

        verticalLayoutAction->addWidget(pushButtonClear);

        pushButtonFocus = new QPushButton(verticalLayoutWidget);
        pushButtonFocus->setObjectName(QStringLiteral("pushButtonFocus"));

        verticalLayoutAction->addWidget(pushButtonFocus);

        horizontalScrollBar = new QScrollBar(centralWidget);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setEnabled(false);
        horizontalScrollBar->setGeometry(QRect(200, 500, 511, 21));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        graphCurve = new QCustomPlot(centralWidget);
        graphCurve->setObjectName(QStringLiteral("graphCurve"));
        graphCurve->setGeometry(QRect(200, 10, 511, 231));
        graphTransf = new QCustomPlot(centralWidget);
        graphTransf->setObjectName(QStringLiteral("graphTransf"));
        graphTransf->setGeometry(QRect(200, 250, 511, 231));
        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(720, 10, 151, 231));
        gridLayoutInput = new QGridLayout(gridLayoutWidget_3);
        gridLayoutInput->setSpacing(6);
        gridLayoutInput->setContentsMargins(11, 11, 11, 11);
        gridLayoutInput->setObjectName(QStringLiteral("gridLayoutInput"));
        gridLayoutInput->setContentsMargins(0, 0, 0, 0);
        groupBoxInput = new QGroupBox(gridLayoutWidget_3);
        groupBoxInput->setObjectName(QStringLiteral("groupBoxInput"));
        labelIn = new QLabel(groupBoxInput);
        labelIn->setObjectName(QStringLiteral("labelIn"));
        labelIn->setGeometry(QRect(14, 15, 131, 201));

        gridLayoutInput->addWidget(groupBoxInput, 0, 0, 1, 1);

        gridLayoutWidget_4 = new QWidget(centralWidget);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(720, 250, 151, 231));
        gridLayoutOuput = new QGridLayout(gridLayoutWidget_4);
        gridLayoutOuput->setSpacing(6);
        gridLayoutOuput->setContentsMargins(11, 11, 11, 11);
        gridLayoutOuput->setObjectName(QStringLiteral("gridLayoutOuput"));
        gridLayoutOuput->setContentsMargins(0, 0, 0, 0);
        groupBoxOutput = new QGroupBox(gridLayoutWidget_4);
        groupBoxOutput->setObjectName(QStringLiteral("groupBoxOutput"));
        labelOut = new QLabel(groupBoxOutput);
        labelOut->setObjectName(QStringLiteral("labelOut"));
        labelOut->setGeometry(QRect(10, 20, 131, 201));

        gridLayoutOuput->addWidget(groupBoxOutput, 0, 0, 1, 1);

        labelVersion = new QLabel(centralWidget);
        labelVersion->setObjectName(QStringLiteral("labelVersion"));
        labelVersion->setGeometry(QRect(730, 490, 141, 21));
        IHM->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(IHM);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 881, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuOpen->setEnabled(true);
        menuFichier = new QMenu(menuOpen);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuEdit->setEnabled(false);
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp->setEnabled(true);
        IHM->setMenuBar(menuBar);
        statusBar = new QStatusBar(IHM);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        IHM->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionFermer);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuOpen->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionWave);
        menuFichier->addAction(actionTexte);
        menuHelp->addAction(actionHelpMe);
        menuHelp->addAction(actionAbout);

        retranslateUi(IHM);

        QMetaObject::connectSlotsByName(IHM);
    } // setupUi

    void retranslateUi(QMainWindow *IHM)
    {
        IHM->setWindowTitle(QApplication::translate("IHM", "IHM", 0));
        actionSave->setText(QApplication::translate("IHM", "Save", 0));
        actionFermer->setText(QApplication::translate("IHM", "Close", 0));
        actionExit->setText(QApplication::translate("IHM", "Exit", 0));
        actionWave->setText(QApplication::translate("IHM", "Wave", 0));
        actionTexte->setText(QApplication::translate("IHM", "Texte", 0));
        actionHelpMe->setText(QApplication::translate("IHM", "Help me", 0));
        actionAbout->setText(QApplication::translate("IHM", "About", 0));
        groupBoxTransf->setTitle(QApplication::translate("IHM", "Transform", 0));
        radioButtonDCT->setText(QApplication::translate("IHM", "DCT", 0));
        radioButtonIDCT->setText(QApplication::translate("IHM", "IDCT", 0));
        groupBoxTime->setTitle(QApplication::translate("IHM", "Time", 0));
        timeEditStart->setDisplayFormat(QApplication::translate("IHM", "mm:ss:zzz", 0));
        timeEditStop->setDisplayFormat(QApplication::translate("IHM", "mm:ss:zzz", 0));
        labelStartTime->setText(QApplication::translate("IHM", "Start Time :", 0));
        labelStopTime->setText(QApplication::translate("IHM", "Stop Time :", 0));
        label->setText(QApplication::translate("IHM", "(Format : M:s:ms)", 0));
        pushButtonStart->setText(QApplication::translate("IHM", "Start", 0));
        pushButtonClear->setText(QApplication::translate("IHM", "Clear", 0));
        pushButtonFocus->setText(QApplication::translate("IHM", "Focus", 0));
        groupBoxInput->setTitle(QApplication::translate("IHM", "Input", 0));
        labelIn->setText(QApplication::translate("IHM", "TextLabel", 0));
        groupBoxOutput->setTitle(QApplication::translate("IHM", "Output", 0));
        labelOut->setText(QApplication::translate("IHM", "TextLabel", 0));
        labelVersion->setText(QApplication::translate("IHM", "Version", 0));
        menuFile->setTitle(QApplication::translate("IHM", "File", 0));
        menuOpen->setTitle(QApplication::translate("IHM", "Open", 0));
        menuFichier->setTitle(QApplication::translate("IHM", "Fichier", 0));
        menuEdit->setTitle(QApplication::translate("IHM", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("IHM", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class IHM: public Ui_IHM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHM_H
