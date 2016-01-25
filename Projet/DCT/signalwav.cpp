#include "signalwav.h"

signalWAV::signalWAV()
{

}


void signalWAV::ReadInfo(const QString name,Signaux::fileInfoStruct *pFileInfo)
{
    string type;

    type = name.toStdString().substr(name.indexOf("."));

    pFileInfo->fileName = QString::fromStdString(name.toStdString().substr(name.lastIndexOf("/")+1));
    pFileInfo->fileType = QString::fromStdString(type);

    pHeader_wav meta = (pHeader_wav)malloc(sizeof(header));
    FILE * infile = fopen(name.toUtf8().constData(),"rb");
    if(infile == NULL)
    {
        qDebug() << "erreur ouverture fichier wav";
    }
    fread(meta, 1, sizeof(header), infile);
    fclose(infile);

    pFileInfo->fileSize = meta->chunk_size;

    long tmp = meta->chunk_size;
    tmp = tmp/long(sizeof(meta->subchunk2_size));
    tmp = tmp/long(meta->sample_rate)*1000; // laisse le x1000 en dernier sinon overflow
    pFileInfo->fileDuration = tmp; // en ms

    free(meta);
}


void signalWAV::ReadData(QString name,QVector<double>& dataX,QVector<double>& dataY)
{
    const int BUFFER_SIZE  = 256;
    long numOfByte = 0;
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

        qDebug() << "byte rate : " << meta->byte_rate << endl;
        qDebug() << "format : " << meta->format << endl;
        qDebug() << "bits per sample : " << meta->bits_per_sample << endl;
        qDebug() << "block_align : " << meta->block_align;
        qDebug() << "chunk_size : " << meta->chunk_size;

        long dataLength =  meta->chunk_size/sizeof(meta->subchunk2_size);

        qDebug() << "data size : " << dataLength << endl;

        while ((nbBytesRead = fread(buffer,1,BUFFER_SIZE,infile))>0)
        {
            if(meta->num_channels == 2) // stéréo
            {
                for (int i = 0; i<nbBytesRead; i = i+4)
                {
                    // on garde que le canal  => left
                    short byte16 = (short(buffer[i+1])<<8) + short(buffer[i]);
                    double data = double(byte16)/(32768);

                    if(numOfByte < dataLength)
                    {
                        dataX.push_back(double(numOfByte)*1/double(meta->sample_rate));
                        dataY.push_back(data);

                        numOfByte++;
                    }
                }
            }
            else
            {
                for (int i = 0; i<nbBytesRead; i = i+2)
                {
                    short byte16 = (short(buffer[i+1])<<8) + short(buffer[i]);
                    double data = double(byte16)/(32768);

                    if(numOfByte < dataLength)
                    {
                        dataX.push_back(double(numOfByte)*1/double(meta->sample_rate));
                        dataY.push_back(data);

                        numOfByte++;
                    }
                }
            }
        }

        fclose(infile);
    }

    free(meta);
}

void signalWAV::SaveData(const QString name,const QVector<double>& dataX,const  QVector<double>& dataY)
{

}
