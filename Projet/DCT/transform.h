#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <Qvector>

class Transform
{
    QVector<double> dataOutX;
    QVector<double> dataOutY;
    int nbPoints;
    int fe;

public:
    Transform();
    ~Transform();

    void startDCT(void);
    void startIDCT(void);

private :
    void dctTransform(void);
    void idctTransform(void);

signals:

public slots:
};

#endif // TRANSFORM_H
