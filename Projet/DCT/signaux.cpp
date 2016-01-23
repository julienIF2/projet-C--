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


void Signaux::SetTime(const QTime start,const QTime stop)
{
    startTime = start;
    stopTime = stop;
}

void Signaux::SaveData(const QString name,const QVector<double> &dataX,const QVector<double> &dataY)
{

}

void Signaux::ReadData(QString name,QVector<double>& dataX,QVector<double>& dataY)
{

}
