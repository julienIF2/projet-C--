#ifndef SIGNALTXT_H
#define SIGNALTXT_H

#include "signaux.h"

#include <QString>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>

using namespace std;

class signalTXT : public Signaux
{
public:
    signalTXT();

    void ReadInfo(QString name);
    void ReadData(QString name);
    void SaveData(const QString name,const QVector<double>& dataX,const QVector<double>& dataY);

};

#endif // SIGNALTXT_H
