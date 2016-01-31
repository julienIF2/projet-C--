#ifndef IHM_H
#define IHM_H

#include <QMainWindow>
#include <qcustomplot.h>

#include <QTime>

#include "transform.h"
#include "signaux.h"
#include "signalcsv.h"
#include "signalwav.h"
#include "signaltxt.h"


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

    void updateGraph(void);

    void updateInSection(QString fileName,QString type,long duration,long size,long nbSample);
    void updateOutSection(QString transformName,int time);

    void enableAllCmd(void);
    void disableAllCmd(void);

private slots:
    void startClick(void);
    void clearClick(void);
    void focusClick(void);
    void toogleBoxSignalWindow(void);
    void toogleBoxCalcWindow(void);

    void openFileClick(void);
    void saveFileClick(void);

    void signalWindow(void);

    void aboutClick(void);

    void updateProgressBar(int value);
};

#endif // IHM_H
