#ifndef SIGNAUX_H
#define SIGNAUX_H

#include <QVector>
#include <QTime>
#include <QString>

using namespace std;

class Signaux
{
private :
    double fileSize;
    double fileDuration;
    QVector<double> dataInX;
    QVector<double> dataInY;
    QTime startTime;
    QTime stopTime;

public:
    Signaux();

    double GetSize();
    double GetDuration();

    void GetData(QVector<double>& dataX,QVector<double>& dataY);
    void SetData(const QVector<double>& dataX,const  QVector<double>& dataY);

    void SetTime(const QTime start,const QTime stop);

    virtual void SaveData(const QString name,const QVector<double> &dataX,const QVector<double> &dataY);

};

#endif // SIGNAUX_H
