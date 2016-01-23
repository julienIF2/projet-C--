#ifndef IHM_H
#define IHM_H

#include <QMainWindow>
#include <qcustomplot.h>

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

    Transform DataCalc;
    signalWAV DataSignal;

    void updateGraph(void);

public slots:
    void startClick(void);
    void clearClick(void);
    void focusClick(void);


};

#endif // IHM_H
