#ifndef SIGNALCSV_H
#define SIGNALCSV_H

#include "signaux.h"

#include <QString>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>

using namespace std;

class signalCSV : public Signaux
{
private:
    QString separator;

public:
    signalCSV();

    void ReadInfo(QString name);
    void ReadData(QString name,QVector<double>& dataX,QVector<double>& dataY);
    void SaveData(const QString name,const QVector<double>& dataX,const QVector<double>& dataY);

    void SetSeparator(QString sep); // par défaut ";"

};

#endif // SIGNALCSV_H
