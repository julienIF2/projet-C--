#ifndef SIGNALWAV_H
#define SIGNALWAV_H

#include "signaux.h"

#include <QString>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

class signalWAV : public Signaux
{
private:

    // WAVE PCM soundfile format (https://ccrma.stanford.edu/courses/422/projects/WaveFormat/ )
    typedef struct header_wav_file
    {
        char chunk_id[4];
        int chunk_size;
        char format[4];
        char subchunk1_id[4];
        int subchunk1_size;
        short int audio_format;
        short int num_channels;
        int sample_rate;
        int byte_rate;
        short int block_align;
        short int bits_per_sample;
        char subchunk2_id[4];
        int subchunk2_size;
    } header;
    typedef struct header_wav_file* pHeader_wav;

public:
    signalWAV();

    void ReadInfo(QString name);
    void ReadData(QString name);
    void SaveData(const QString name,const QVector<double>& dataX,const  QVector<double>& dataY);

};

#endif // SIGNALWAV_H
