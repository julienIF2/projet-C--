#include "signaltxt.h"

signalTXT::signalTXT()
{

}

void signalTXT::ReadInfo(const QString name,Signaux::fileInfoStruct *pFileInfo)
{
    string type;

    type = name.toStdString().substr(name.indexOf("."));

    pFileInfo->fileName = QString::fromStdString(name.toStdString().substr(name.lastIndexOf("/")+1));
    pFileInfo->fileType = QString::fromStdString(type);
    pFileInfo->fileDuration =0; // durée inconnue

    ifstream file;
    file.open(name.toUtf8().constData());
    long pos = file.tellg();
    file.seekg( 0 , std::ios_base::end ); // on se place à la fin du fichier
    pFileInfo->fileSize =file.tellg(); // la position fin = taille en octects
    file.seekg( pos,  std::ios_base::beg ) ;
    file.close();
}


void signalTXT::ReadData(QString name,QVector<double>& dataX,QVector<double>& dataY)
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
           tempList = temp.split(",");
           dataX.push_back(QString(tempList[0]).toDouble());
           dataY.push_back(QString(tempList[1]).toDouble());
       }

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
