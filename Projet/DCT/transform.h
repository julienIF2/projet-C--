#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <Qvector>
#include <math.h>
#include <omp.h>
#include <QObject>

#include <QCoreApplication>

using namespace std;

// TODO
// utiliser open mp pour accélérer les calcules...


#define HANNING "Hanning"
#define HAMMING "Hamming"
#define RECTANGULAR "Rectangular"


class Transform : public QObject
{
    Q_OBJECT

private :
    void windowing(QString window,unsigned long N,QVector<double> &coeff,double &correction);

public:
    Transform();
    ~Transform();

    void getWindowsType(QStringList &listOfWindows);

    void dctTransform(const QVector<double> &Xin,const QVector<double> &Yin,
                                 QVector<double> &Xout,QVector<double> &Yout,
                                 QString window,unsigned long wSize);
    void idctTransform(const QVector<double> &Xin,const QVector<double> &Yin,
                                 QVector<double> &Xout,QVector<double> &Yout,
                                 QString window,unsigned long wSize);

signals:
    void progressionSignal(int pourcent);

};

#endif // TRANSFORM_H
