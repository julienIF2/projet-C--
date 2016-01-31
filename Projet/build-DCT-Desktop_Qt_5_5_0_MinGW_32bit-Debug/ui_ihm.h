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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
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
    QAction *actionCSV;
    QAction *actionOpen;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayoutTransf;
    QGroupBox *groupBoxTransf;
    QRadioButton *radioButtonDCT;
    QRadioButton *radioButtonIDCT;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayoutSignalWindow;
    QGroupBox *groupBoxSignalWindow;
    QTimeEdit *timeEditStart;
    QTimeEdit *timeEditStop;
    QLabel *labelStartSignalWindow;
    QLabel *labelStopSignalWindow;
    QLabel *label;
    QCheckBox *enableSignalWindow;
    QPushButton *pushButtonWindowing;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutAction;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonFocus;
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
    QProgressBar *progressBar;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayoutCalcWindow;
    QGroupBox *groupBoxCalcWindow;
    QLabel *labelCalcWindow;
    QCheckBox *enableCalcWindow;
    QSpinBox *spinBoxCalcWindow;
    QLabel *labelCalcWindow_2;
    QComboBox *comboBoxCalcWindow;
    QLabel *labelCalcWindow_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IHM)
    {
        if (IHM->objectName().isEmpty())
            IHM->setObjectName(QStringLiteral("IHM"));
        IHM->resize(1060, 648);
        IHM->setAcceptDrops(false);
        actionSave = new QAction(IHM);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(true);
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
        actionCSV = new QAction(IHM);
        actionCSV->setObjectName(QStringLiteral("actionCSV"));
        actionOpen = new QAction(IHM);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralWidget = new QWidget(IHM);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 181, 91));
        gridLayoutTransf = new QGridLayout(gridLayoutWidget);
        gridLayoutTransf->setSpacing(6);
        gridLayoutTransf->setContentsMargins(11, 11, 11, 11);
        gridLayoutTransf->setObjectName(QStringLiteral("gridLayoutTransf"));
        gridLayoutTransf->setContentsMargins(0, 0, 0, 0);
        groupBoxTransf = new QGroupBox(gridLayoutWidget);
        groupBoxTransf->setObjectName(QStringLiteral("groupBoxTransf"));
        radioButtonDCT = new QRadioButton(groupBoxTransf);
        radioButtonDCT->setObjectName(QStringLiteral("radioButtonDCT"));
        radioButtonDCT->setGeometry(QRect(20, 20, 95, 20));
        radioButtonDCT->setChecked(true);
        radioButtonIDCT = new QRadioButton(groupBoxTransf);
        radioButtonIDCT->setObjectName(QStringLiteral("radioButtonIDCT"));
        radioButtonIDCT->setGeometry(QRect(20, 50, 95, 20));

        gridLayoutTransf->addWidget(groupBoxTransf, 0, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 110, 181, 191));
        gridLayoutSignalWindow = new QGridLayout(gridLayoutWidget_2);
        gridLayoutSignalWindow->setSpacing(6);
        gridLayoutSignalWindow->setContentsMargins(11, 11, 11, 11);
        gridLayoutSignalWindow->setObjectName(QStringLiteral("gridLayoutSignalWindow"));
        gridLayoutSignalWindow->setContentsMargins(0, 0, 0, 0);
        groupBoxSignalWindow = new QGroupBox(gridLayoutWidget_2);
        groupBoxSignalWindow->setObjectName(QStringLiteral("groupBoxSignalWindow"));
        groupBoxSignalWindow->setEnabled(true);
        timeEditStart = new QTimeEdit(groupBoxSignalWindow);
        timeEditStart->setObjectName(QStringLiteral("timeEditStart"));
        timeEditStart->setGeometry(QRect(60, 50, 101, 22));
        timeEditStart->setCurrentSection(QDateTimeEdit::MinuteSection);
        timeEditStop = new QTimeEdit(groupBoxSignalWindow);
        timeEditStop->setObjectName(QStringLiteral("timeEditStop"));
        timeEditStop->setGeometry(QRect(60, 90, 101, 22));
        labelStartSignalWindow = new QLabel(groupBoxSignalWindow);
        labelStartSignalWindow->setObjectName(QStringLiteral("labelStartSignalWindow"));
        labelStartSignalWindow->setGeometry(QRect(10, 50, 41, 16));
        labelStopSignalWindow = new QLabel(groupBoxSignalWindow);
        labelStopSignalWindow->setObjectName(QStringLiteral("labelStopSignalWindow"));
        labelStopSignalWindow->setGeometry(QRect(10, 90, 41, 20));
        label = new QLabel(groupBoxSignalWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 120, 131, 16));
        enableSignalWindow = new QCheckBox(groupBoxSignalWindow);
        enableSignalWindow->setObjectName(QStringLiteral("enableSignalWindow"));
        enableSignalWindow->setEnabled(true);
        enableSignalWindow->setGeometry(QRect(20, 20, 81, 20));
        pushButtonWindowing = new QPushButton(groupBoxSignalWindow);
        pushButtonWindowing->setObjectName(QStringLiteral("pushButtonWindowing"));
        pushButtonWindowing->setGeometry(QRect(0, 140, 179, 28));

        gridLayoutSignalWindow->addWidget(groupBoxSignalWindow, 0, 0, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 470, 181, 121));
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

        graphCurve = new QCustomPlot(centralWidget);
        graphCurve->setObjectName(QStringLiteral("graphCurve"));
        graphCurve->setGeometry(QRect(200, 10, 691, 271));
        graphTransf = new QCustomPlot(centralWidget);
        graphTransf->setObjectName(QStringLiteral("graphTransf"));
        graphTransf->setGeometry(QRect(200, 290, 691, 261));
        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(900, 0, 151, 231));
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
        gridLayoutWidget_4->setGeometry(QRect(900, 250, 151, 231));
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

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(200, 560, 701, 23));
        progressBar->setValue(24);
        gridLayoutWidget_5 = new QWidget(centralWidget);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 310, 181, 151));
        gridLayoutCalcWindow = new QGridLayout(gridLayoutWidget_5);
        gridLayoutCalcWindow->setSpacing(6);
        gridLayoutCalcWindow->setContentsMargins(11, 11, 11, 11);
        gridLayoutCalcWindow->setObjectName(QStringLiteral("gridLayoutCalcWindow"));
        gridLayoutCalcWindow->setContentsMargins(0, 0, 0, 0);
        groupBoxCalcWindow = new QGroupBox(gridLayoutWidget_5);
        groupBoxCalcWindow->setObjectName(QStringLiteral("groupBoxCalcWindow"));
        groupBoxCalcWindow->setEnabled(true);
        labelCalcWindow = new QLabel(groupBoxCalcWindow);
        labelCalcWindow->setObjectName(QStringLiteral("labelCalcWindow"));
        labelCalcWindow->setGeometry(QRect(10, 50, 41, 20));
        enableCalcWindow = new QCheckBox(groupBoxCalcWindow);
        enableCalcWindow->setObjectName(QStringLiteral("enableCalcWindow"));
        enableCalcWindow->setEnabled(true);
        enableCalcWindow->setGeometry(QRect(20, 20, 81, 20));
        spinBoxCalcWindow = new QSpinBox(groupBoxCalcWindow);
        spinBoxCalcWindow->setObjectName(QStringLiteral("spinBoxCalcWindow"));
        spinBoxCalcWindow->setGeometry(QRect(70, 50, 101, 22));
        labelCalcWindow_2 = new QLabel(groupBoxCalcWindow);
        labelCalcWindow_2->setObjectName(QStringLiteral("labelCalcWindow_2"));
        labelCalcWindow_2->setGeometry(QRect(80, 80, 71, 21));
        comboBoxCalcWindow = new QComboBox(groupBoxCalcWindow);
        comboBoxCalcWindow->setObjectName(QStringLiteral("comboBoxCalcWindow"));
        comboBoxCalcWindow->setGeometry(QRect(70, 110, 101, 22));
        labelCalcWindow_3 = new QLabel(groupBoxCalcWindow);
        labelCalcWindow_3->setObjectName(QStringLiteral("labelCalcWindow_3"));
        labelCalcWindow_3->setGeometry(QRect(10, 110, 61, 21));

        gridLayoutCalcWindow->addWidget(groupBoxCalcWindow, 0, 0, 1, 1);

        IHM->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(IHM);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1060, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
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
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
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
        actionCSV->setText(QApplication::translate("IHM", "CSV", 0));
        actionOpen->setText(QApplication::translate("IHM", "Open", 0));
        groupBoxTransf->setTitle(QApplication::translate("IHM", "Transform", 0));
        radioButtonDCT->setText(QApplication::translate("IHM", "DCT", 0));
        radioButtonIDCT->setText(QApplication::translate("IHM", "IDCT", 0));
        groupBoxSignalWindow->setTitle(QApplication::translate("IHM", "Signal Window", 0));
        timeEditStart->setDisplayFormat(QApplication::translate("IHM", "mm:ss:zzz", 0));
        timeEditStop->setDisplayFormat(QApplication::translate("IHM", "mm:ss:zzz", 0));
        labelStartSignalWindow->setText(QApplication::translate("IHM", "Start :", 0));
        labelStopSignalWindow->setText(QApplication::translate("IHM", "Stop :", 0));
        label->setText(QApplication::translate("IHM", "(Format : M:s:ms)", 0));
        enableSignalWindow->setText(QApplication::translate("IHM", "Enable", 0));
        pushButtonWindowing->setText(QApplication::translate("IHM", "Windowing", 0));
        pushButtonStart->setText(QApplication::translate("IHM", "Start", 0));
        pushButtonClear->setText(QApplication::translate("IHM", "Clear", 0));
        pushButtonFocus->setText(QApplication::translate("IHM", "Focus", 0));
        groupBoxInput->setTitle(QApplication::translate("IHM", "Input", 0));
        labelIn->setText(QString());
        groupBoxOutput->setTitle(QApplication::translate("IHM", "Output", 0));
        labelOut->setText(QString());
        groupBoxCalcWindow->setTitle(QApplication::translate("IHM", "Calculation Window", 0));
        labelCalcWindow->setText(QApplication::translate("IHM", "Size :", 0));
        enableCalcWindow->setText(QApplication::translate("IHM", "Enable", 0));
        labelCalcWindow_2->setText(QApplication::translate("IHM", "(nb of ech)", 0));
        labelCalcWindow_3->setText(QApplication::translate("IHM", "Type :", 0));
        menuFile->setTitle(QApplication::translate("IHM", "File", 0));
        menuEdit->setTitle(QApplication::translate("IHM", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("IHM", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class IHM: public Ui_IHM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHM_H
