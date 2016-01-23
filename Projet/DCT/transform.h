#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <Qvector>
#include <math.h>
#include <omp.h>

using namespace std;

// TODO
// utiliser open mp pour accélérer les calcules...

class Transform
{
    QVector<double> dataInX;
    QVector<double> dataInY;
    QVector<double> dataOutX;
    QVector<double> dataOutY;
    int nbPoints;
    int fe;

public:
    Transform();
    ~Transform();

    void startDCT(void);
    void startIDCT(void);

    void GetData(QVector<double>& dataX,QVector<double>& dataY);
    void SetData(const QVector<double>& dataX,const  QVector<double>& dataY);

private :
    void dctTransform(void);
    void idctTransform(void);



};

#endif // TRANSFORM_H
