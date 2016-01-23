#include "signalwav.h"

signalWAV::signalWAV()
{

}


void signalWAV::ReadInfo(QString name)
{

}


void signalWAV::ReadData(QString name,QVector<double>& dataX,QVector<double>& dataY)
{
    const int BUFFER_SIZE  = 256;
    int numOfByte = 0;
    unsigned char buffer[BUFFER_SIZE]={0};
    pHeader_wav meta = (pHeader_wav)malloc(sizeof(header));
    int nbBytesRead;

    FILE * infile = fopen(name.toUtf8().constData(),"rb");
    if(infile == NULL)
    {
        qDebug() << "erreur ouverture fichier wav";
    }
    else
    {
        dataX.clear();
        dataY.clear();

        fread(meta, 1, sizeof(header), infile);

        qDebug() << "first chunk is :" << sizeof(meta->chunk_id) << " bytes in size" << endl;
        qDebug() << "The file is a :" << meta->chunk_id << " format" << endl;
        qDebug() << " Size of Header file is "<<sizeof(*meta)<<" bytes" << endl;
        qDebug() << " Sampling rate of the input wave file is "<< meta->sample_rate <<" Hz" << endl;
        qDebug() << " Size of data in the audio is: " << sizeof(meta->subchunk2_size)<< " bytes" << endl;
        qDebug() << " The number of channels of the file is "<< meta->num_channels << " channels" << endl;
        qDebug() << " The audio format is PCM:"<< meta->audio_format << endl;

        while ((nbBytesRead = fread(buffer,1,BUFFER_SIZE,infile))>0)
        {
            for (int i = 0; i<nbBytesRead; i = i+2)
            {
                short byte16 = (short(buffer[i+1])<<8) + short(buffer[i]);
                double data = double(byte16)/(32768);

                dataX.push_back(double(numOfByte)*1/double(meta->sample_rate));
                dataY.push_back(data);

                numOfByte++;
            }
        }

        fclose(infile);
    }

    free(meta);
}

void signalWAV::SaveData(const QString name,const QVector<double>& dataX,const  QVector<double>& dataY)
{

}
