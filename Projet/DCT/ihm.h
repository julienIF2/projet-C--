#ifndef IHM_H
#define IHM_H

#include <QMainWindow>
#include <qcustomplot.h>

#include "transform.h"
#include "signaux.h"
#include "signalcsv.h"
#include "signalwav.h"
#include "signaltxt.h"
#include "dialog.h"

using namespace std;

namespace Ui {
class IHM;
}

class IHM : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM(QWidget *parent = 0);
    ~IHM();

private:
    Ui::IHM *ui;

private :
    QVector<double> dataInX;
    QVector<double> dataInY;
    QVector<double> dataOutX;
    QVector<double> dataOutY;

    Transform DataCalc;
    Signaux *pDataSignal;
    Dialog msgBox;

    void updateGraph(void);
    void openDialogBox(QString title,QString txt);

    void updateInSection(QString file,QString type,int duration,int size);
    void updateOutSection(QString transformName,int time);

    void enableAllCmd(void);
    void disableAllCmd(void);

private slots:
    void startClick(void);
    void clearClick(void);
    void focusClick(void);

    void openFileClick(void);
    void saveFileClick(void);

    void aboutClick(void);

    void updateProgressBar(int value);
};

#endif // IHM_H
