#ifndef SIGNALTXT_H
#define SIGNALTXT_H

#include "signaux.h"

#include <QString>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>
#include <fstream>

using namespace std;

class signalTXT : public Signaux
{
public:
    signalTXT();

    void ReadInfo(const QString name,Signaux::fileInfoStruct *pFileInfo);
    void ReadData(QString name,QVector<double>& dataX,QVector<double>& dataY);
    void SaveData(const QString name,const QVector<double>& dataX,const QVector<double>& dataY);

};

#endif // SIGNALTXT_H
