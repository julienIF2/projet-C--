#include "signaltxt.h"

signalTXT::signalTXT()
{

}

void signalTXT::ReadInfo(QString name)
{

}


void signalTXT::ReadData(QString name)
{
    QFile file(name);

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "erreur ouverture fichier ReadData CSV";
    }
    else
    {
       QTextStream in(&file);
       QVector<double> dataX,dataY;
       QString temp;
       QStringList tempList;
       while (!in.atEnd())
       {
           temp = in.readLine();
           tempList = temp.split(",");
           dataX.push_back(QString(tempList[0]).toDouble());
           dataY.push_back(QString(tempList[1]).toDouble());
       }

       SetData(dataX,dataY);

       dataX.clear();
       dataY.clear();

       file.close();
    }
}

void signalTXT::SaveData(const QString name,const QVector<double>& dataX,const  QVector<double>& dataY)
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
            out << dataX[i] <<";"<<dataY[i]<<"\n";
        }
        file.close();
    }
}
