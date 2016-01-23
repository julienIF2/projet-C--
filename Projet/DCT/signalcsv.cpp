#include "signalcsv.h"

signalCSV::signalCSV()
{
    separator = ";";
}

void signalCSV::ReadInfo(QString name)
{

}


void signalCSV::ReadData(QString name,QVector<double>& dataX,QVector<double>& dataY)
{
    QFile file(name);

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "erreur ouverture fichier ReadData CSV";
    }
    else
    {
       QTextStream in(&file);
       QString temp;
       QStringList tempList;

       dataX.clear();
       dataY.clear();

       while (!in.atEnd())
       {
           temp = in.readLine();
           tempList = temp.split(separator);
           dataX.push_back(QString(tempList[0]).toDouble());
           dataY.push_back(QString(tempList[1]).toDouble());
       }

       file.close();
    }
}

void signalCSV::SaveData(const QString name,const QVector<double>& dataX,const  QVector<double>& dataY)
{
    QFile file(name);

    if(dataX.size() != dataY.size())
    {
        qDebug() << "erreur vecteur de taille diff SaveData CSV";
    }

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "erreur ouverture fichier ReadData CSV";
    }
    else
    {
        QTextStream out(&file);
        double i;

        for(i = 0; i < dataX.size();i++)
        {
            out << dataX[i] <<separator<<dataY[i]<<"\n";
        }
        file.close();
    }
}

void signalCSV::SetSeparator(QString sep)
{
    separator = sep;
}
