#include "signalwav.h"

signalWAV::signalWAV()
{

}


void signalWAV::ReadInfo(const QString name,Signaux::fileInfoStruct *pFileInfo)
{
    string type;

    type = name.toStdString().substr(name.indexOf("."));  // Récupération du type

    pFileInfo->fileName = QString::fromStdString(name.toStdString().substr(name.lastIndexOf("/")+1));
    pFileInfo->fileType = QString::fromStdString(type);

    pHeader_wav meta = (pHeader_wav)malloc(sizeof(header)); // Allocation d'une structure d'un header wav
    FILE * infile = fopen(name.toUtf8().constData(),"rb");
    if(infile == NULL)
    {
        qDebug() << "erreur ouverture fichier wav";
    }
    fread(meta, 1, sizeof(header), infile); // Lecture de toutes les données de l'header
    fclose(infile);

    pFileInfo->fileSize = meta->chunk_size;   // Taille du fichier

    long tmp = meta->chunk_size;
    tmp = tmp/long(sizeof(meta->subchunk2_size));
    tmp = tmp/long(meta->sample_rate)*1000; // laisse le x1000 en dernier sinon overflow
    pFileInfo->fileDuration = tmp; // en ms


    pFileInfo->nbSample = (meta->chunk_size-meta->subchunk1_size-meta->subchunk2_size-20-8)/4; // 8 -> chunk id et 20 header

    free(meta); // Désallocation de la structure
}


void signalWAV::ReadData(QString name,QVector<double>& dataX,QVector<double>& dataY)
{
    const int BUFFER_SIZE  = 256;
    long numOfByte = 0;
    unsigned char buffer[BUFFER_SIZE]={0};
    pHeader_wav meta = (pHeader_wav)malloc(sizeof(header)); // structure d'un header
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

        fread(meta, 1, sizeof(header), infile); // Lecture de l'header


        /* DEBUG */
        qDebug() << "byte rate : " << meta->byte_rate << endl;
        qDebug() << "format : " << meta->format << endl;
        qDebug() << "bits per sample : " << meta->bits_per_sample << endl;
        qDebug() << "block_align : " << meta->block_align;
        qDebug() << "chunk_size : " << meta->chunk_size;


        /* Calcul de la taille */
        long dataLength = (meta->chunk_size-meta->subchunk1_size-meta->subchunk2_size-20-8)/4; // 8 -> chunk id et 20 header

        qDebug() << "data size : " << dataLength << endl;

        while ((nbBytesRead = fread(buffer,1,BUFFER_SIZE,infile))>0) // Lecture des data
        {
            if(meta->num_channels == 2) // stéréo -> on récupère qu'un channel (channel0 -> Left et channel1 -> right)
            {
                for (int i = 0; i<nbBytesRead; i = i+4)
                {
                    // on garde que le canal  => left
                    short byte16 = (short(buffer[i+1])<<8) + short(buffer[i]); // MSB + LSB => convertion en 16bits
                    double data = double(byte16)/(32768);   // normalisation -> les fichiers wav sont normalisés par rapport à la valeur max de leur signal

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
                for (int i = 0; i<nbBytesRead; i = i+2) // mono
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
    /*pHeader_wav meta = (pHeader_wav)malloc(sizeof(header));

    FILE * infile = fopen(name.toUtf8().constData(),"w+");
    if(infile == NULL)
    {
        qDebug() << "erreur ouverture fichier wav";
    }
    else
    {
        meta->audio_format = 1;
        meta->bits_per_sample = 16;
        meta->block_align = 2;
        meta->byte_rate = 176400/2; // TODO modif

        meta->chunk_id[0] = 'R';
        meta->chunk_id[1] = 'I';
        meta->chunk_id[2] = 'F';
        meta->chunk_id[3] = 'F';

        meta->chunk_size = (1764070-70)/2;

        meta->format[0] = 'W';
        meta->format[1] = 'A';
        meta->format[2] = 'V';
        meta->format[3] = 'E';

        meta->num_channels = 1;
        meta->sample_rate = 44100;

        meta->subchunk1_id[0] = 'f';
        meta->subchunk1_id[1] = 'm';
        meta->subchunk1_id[2] = 't';

        meta->subchunk1_size = 16;

        meta->subchunk2_id[0] = 'L';
        meta->subchunk2_id[1] = 'I';
        meta->subchunk2_id[2] = 'S';
        meta->subchunk2_id[3] = 'T';

        meta->subchunk2_size = 26;



        fwrite(meta, 1, sizeof(header), infile); // Lecture de l'header

        char remplissage[26] = {0};
        fwrite(remplissage, 1, sizeof(remplissage), infile);

        char data[4] = {'d','a','t','a'};
        fwrite(data, 1, sizeof(data), infile);

        unsigned long nbWritten = 0;
        char byte[2];

        while(nbWritten < dataY.size())
        {
            byte[0] = (int(dataY[nbWritten]*32768))*0x00FF;
            byte[1] = ((int(dataY[nbWritten]*32768))*0xFF00)>>8;
            fwrite(byte,1,sizeof(byte),infile);

            nbWritten++;
        }

        fclose(infile);
    }



    free(meta);*/
}
