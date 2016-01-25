#ifndef SIGNAUX_H
#define SIGNAUX_H

#include <QVector>
#include <QTime>
#include <QString>

using namespace std;

class Signaux
{
public :
    struct fileInfoStruct
    {
        QString fileName;
        QString fileType;
        long fileSize;
        long fileDuration;
    };
    typedef struct fileInfoStruct fileInfoStruct;

    Signaux();

    // TODO => abstract
    virtual void ReadInfo(const QString name,fileInfoStruct *pFileInfo) = 0;
    virtual void SaveData(const QString name,const QVector<double> &dataX,const QVector<double> &dataY) = 0;
    virtual void ReadData(QString name,QVector<double>& dataX,QVector<double>& dataY) = 0;

};

#endif // SIGNAUX_H
