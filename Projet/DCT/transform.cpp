#include "transform.h"
#include <omp.h>

#include <QTime>
#include <QDebug>



Transform::Transform()
{
}

Transform::~Transform()
{

}

void Transform::dctTransform(const QVector<double> &Xin,const QVector<double> &Yin,
                             QVector<double> &Xout,QVector<double> &Yout,
                             QString window,unsigned long wSize)
{
   double w,Fe,sum,correction;
   QTime t;
   int state;
   unsigned long N,nSampleCalculated = 0,nSample,nbOfWindow = 0; // nbOfWindow just to debug
   QVector<double> tempInY,tempOutY,coeff,saveCoeff;

   /* Récupération de la taille du signal d'entrée */
   N = Xin.size();

   t.start();
   state = t.elapsed(); // ms

   /* Calcul des valeurs de l'axe X */
   Fe = 1/(Xin[1]-Xin[0]);

   /* Remise à l'état initial des vecteurs */
   Xout.clear();
   Yout.clear();

   Xout.resize(N);
   #pragma omp parallel for
  for(unsigned long a=0;a<N;a++)
  {
      Xout[a] = ((double)Fe)/(2*N)*((double)a); // Calcul des fréquences
  }

   if(N >= 2)  // 2 echantillions minimum => Fe
   {
       do
       {
           /* Calcul de la portion de signal */
           if((N-nSampleCalculated)>= wSize)
           {
               nSample = wSize;
           }
           else
           {
               nSample = N-nSampleCalculated;
           }

           /* Calcul de coefficient pour éviter de la faire à chaque boucle */
           saveCoeff.resize(nSample);
           #pragma omp parallel for
           for(unsigned long a=0;a<nSample;a++)
           {
               saveCoeff[a] = (((double)M_PI)/nSample*a);
           }

           /* Récupération du fenêtrage */
           windowing(window,nSample,coeff,correction);
           for(unsigned long i=0;i<nSample;i++)
           {
               tempInY.push_back(coeff[i]*Yin[i+nSampleCalculated]);
           }
           coeff.clear();

           /* Boucle de calcul */
           for(unsigned long k=0;k<nSample;k++)
           {
               QCoreApplication::processEvents(); // permet de signal à window que le processus fonction bien
               if((t.elapsed()-state) > 1000) // 1s
               {
                   emit progressionSignal((int)k+nSampleCalculated); // mise à jours toutes les secondes de l'état d'avancement
                   state = t.elapsed();
               }

               /* Calcul de la somme des N valeur */
                sum = 0;
               #pragma omp parallel for reduction(+:sum)
               for(unsigned long j=0;j<nSample;j++)
               {
                  sum += tempInY[j]*cos(saveCoeff[j]*k);
               }

               /* Calcul du facteur w */
               if(k==0)
               {
                   w = 1/sqrt(((double)nSample));
               }
               else
               {
                   w = sqrt(2/((double)nSample));
               }
               /* Remplissage du vecteur contenant la DCT */
               tempOutY.push_back(w*sum);
           }
           saveCoeff.clear();

           tempInY.clear();

           Yout += tempOutY;

           tempOutY.clear();

           nSampleCalculated += nSample;

           nbOfWindow++;
       }while(nSampleCalculated < N);
   }

}

void Transform::idctTransform(const QVector<double> &Xin,const QVector<double> &Yin,
                              QVector<double> &Xout,QVector<double> &Yout,
                              QString window,unsigned long wSize)
{
    double sum,w,deltaT,correction;
    unsigned long M;
    unsigned long nSampleCalculated = 0,nSample,nbOfWindow = 0; // nbOfWindow just to debug
    QVector<double> tempInY,tempOutX,tempOutY,coeff,saveCoeff;
    int state;
    QTime t;

    /* Récupération de la taille du signal d'entrée */
    M = Xin.size();


    t.start();
    state = t.elapsed(); // ms

    /* Remise à l'état initial des vecteurs */
    Xout.clear();
    Yout.clear();

    Xout.resize(M);

   /* Calcul des valeurs de l'axe X */
   deltaT = 1/(Xin[1]-Xin[0]);

   #pragma omp parallel for
   for(unsigned long k=0;k<M;k++)
   {
       Xout[k] = ((double)deltaT)*k/M;  // Calcul des temps
   }

    if(M >= 2)
    {
        do
        {
            /* Calcul de la portion de signal */
            if((M-nSampleCalculated)>= wSize)
            {
                nSample = wSize;
            }
            else
            {
                nSample = M-nSampleCalculated;
            }

            for(unsigned long i=0;i<nSample;i++)
            {
                tempInY.push_back(Yin[i+nSampleCalculated]);
            }

            for(unsigned long m=0;m<nSample;m++)
            {

                QCoreApplication::processEvents();
                if((t.elapsed()-state) > 1000) // 1s
                {
                    emit progressionSignal((int)m+nSampleCalculated);
                    state = t.elapsed();
                }

                sum = 0;
               #pragma omp parallel for reduction(+:sum)
                for(unsigned long k=0;k<nSample;k++)
                {
                    /* Calcul du facteur w */
                    if(k==0)
                    {
                        w = 1/sqrt(((double)nSample));
                    }
                    else
                    {
                        w = sqrt(2/((double)nSample));
                    }


                    sum += w*tempInY[k]*cos(((double)M_PI)*(2*m-1)*(k)/(2*nSample+1));
                }
                /* Remplissage du vecteur contenant la IDCT */
                tempOutY.push_back(sum);
            }

            tempInY.clear();

            // dé-fenetrage
            windowing(window,nSample,coeff,correction);

            #pragma omp parallel for
            for(unsigned long i=0;i<nSample;i++)
            {
                tempOutY[i] *= 1/coeff[i];
            }
            coeff.clear();


            Yout += tempOutY;

            tempOutX.clear();
            tempOutY.clear();

            nSampleCalculated += nSample;

            nbOfWindow++;

            qDebug() << nbOfWindow; // TODO SUPPR
        }while(nSampleCalculated < M);
    }
}


void Transform:: windowing(QString window,unsigned long N,QVector<double> &coeff,double &correction)
{
    double theta;

    correction = 1;

    if(window == HANNING)
    {
        theta = ((double)M_PI)/N;
        for(unsigned long i=0;i<N;i++)
        {
            coeff.push_back(0.54 + 0.46 * cos(((double)i) * theta));
        }

        // TODO calcul correction
    }

    if(window == HAMMING)
    {              
        theta = ((double)M_PI)/N;
        for(unsigned long i=0;i<N;i++)
        {
            coeff.push_back(0.5 + 0.5 * cos(((double)i) * theta));
        }
}
    else // defulat => RECTANGULAR
    {
        for(unsigned long i=0;i<N;i++)
        {
            coeff.push_back(1);
        }
    }
}

void Transform::getWindowsType(QStringList &listOfWindows)
{
    listOfWindows.push_back(HANNING);
    listOfWindows.push_back(HAMMING);
    listOfWindows.push_back(RECTANGULAR);
}
