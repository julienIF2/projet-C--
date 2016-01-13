#ifndef QIHM_H
#define QIHM_H

#include <QMainWindow>

namespace Ui {
class QIHM;
}

class QIHM : public QMainWindow
{
    Q_OBJECT

public:
    explicit QIHM(QWidget *parent = 0);
    ~QIHM();

private:
    Ui::QIHM *ui;
};

#endif // QIHM_H
