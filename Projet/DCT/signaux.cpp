#include "signaux.h"

Signaux::Signaux()
{

}

double Signaux::GetSize()
{
    return fileSize;
}

double Signaux::GetDuration()
{
    return fileDuration;
}

void Signaux::GetData(QVector<double>& dataX,QVector<double>& dataY)
{
    dataX = dataInX;
    dataY = dataInY;
}


void Signaux::SetData(const QVector<double>& dataX,const  QVector<double>& dataY)
{
    dataInX.clear();
    dataInY.clear();

    dataInX = dataX;
    dataInY = dataY;
}

void Signaux::SetTime(const QTime start,const QTime stop)
{
    startTime = start;
    stopTime = stop;
}

void Signaux::SaveData(const QString name,const QVector<double> &dataX,const QVector<double> &dataY)
{

}
