/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *labelDialogInfo;
    QPushButton *pushButtonDialogCancel;
    QPushButton *pushButtonDialogContinue;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        labelDialogInfo = new QLabel(Dialog);
        labelDialogInfo->setObjectName(QStringLiteral("labelDialogInfo"));
        labelDialogInfo->setGeometry(QRect(50, 30, 301, 201));
        pushButtonDialogCancel = new QPushButton(Dialog);
        pushButtonDialogCancel->setObjectName(QStringLiteral("pushButtonDialogCancel"));
        pushButtonDialogCancel->setGeometry(QRect(230, 240, 93, 28));
        pushButtonDialogContinue = new QPushButton(Dialog);
        pushButtonDialogContinue->setObjectName(QStringLiteral("pushButtonDialogContinue"));
        pushButtonDialogContinue->setGeometry(QRect(120, 240, 93, 28));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        labelDialogInfo->setText(QApplication::translate("Dialog", "Informations diverses", 0));
        pushButtonDialogCancel->setText(QApplication::translate("Dialog", "Cancel", 0));
        pushButtonDialogContinue->setText(QApplication::translate("Dialog", "Continue", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
