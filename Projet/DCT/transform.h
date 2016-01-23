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

class Transform : public QObject
{
    Q_OBJECT

public:
    Transform();
    ~Transform();

    void dctTransform(const QVector<double> &Xin,const QVector<double> &Yin,QVector<double> &Xout,QVector<double> &Yout);
    void idctTransform(const QVector<double> &Xin,const QVector<double> &Yin,QVector<double> &Xout,QVector<double> &Yout);

signals:
    void progressionSignal(int pourcent);

};

#endif // TRANSFORM_H
