#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public :
    bool flagError;
private :
    QString titleString;
    QString infoString;

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void setTitle(QString title);
    void setInfo(QString info);

    void updateDialogBox(void);

public slots :
    void cancelClick(void);
    void continueClick(void);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
