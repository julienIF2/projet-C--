#include "transform.h"
#include <omp.h>

Transform::Transform()
{
    connect(this,SIGNAL(progressionSignal(int)),this,SLOT(progressionSlot(int)));
}

Transform::~Transform()
{

}

void Transform::dctTransform(const QVector<double> &Xin,const QVector<double> &Yin,QVector<double> &Xout,QVector<double> &Yout)
{
   double somme;
   double k,j,N;
   double w;
   double Fe;
   double state=0,deltaProgression;

   /* Récupération de la taille du signal d'entrée */
   N = Xin.size();
   deltaProgression = 0.001*N;
   if(N != 0)
   {

       /* Remise à l'état initial des vecteurs */
       Xout.clear();
       Yout.clear();

       /* Calcul des valeurs de l'axe X */
       Fe = 1/(Xin[1]-Xin[0]);
       for(k=0;k<N;k++)
       {
           Xout.push_back(Fe/2*k/N);
       }

       for(k=0;k<N;k++)
       {
           QCoreApplication::processEvents();
           if(k > (state+deltaProgression) )
           {
               emit progressionSignal((int)k);
               state = k;
           }

           /* Calcul de la somme des N valeur */
           somme = 0;
           for(j=0;j<N;j++)
           {
               somme += Yin[j]*cos(M_PI/(2*N)*(2*j)*k);
           }
           /* Calcul du facteur w */
           if(k==1)
           {
               w = 1/sqrt(N);
           }
           else
           {
               w = sqrt(2/N);
           }
           /* Remplissage du vecteur contenant la DCT */
           Yout.push_back(w*somme);
       }
   }
   emit progressionSignal(100);
}

void Transform::idctTransform(const QVector<double> &Xin,const QVector<double> &Yin,QVector<double> &Xout,QVector<double> &Yout)
{
    double somme;
    double m,k,M,w;
    double deltaT;
    double state=0,deltaProgression;

    /* Récupération de la taille du signal d'entrée */
    M = Xin.size();
    deltaProgression = 0.001*M;
    if(M != 0)
    {
        /* Remise à l'état initial des vecteurs */
        Xout.clear();
        Yout.clear();

        /* Calcul des valeurs de l'axe X */
        deltaT = 1/(Xin[1]-Xin[0]);
        for(k=0;k<M;k++)
        {
            Xout.push_back(deltaT*k/M);
        }

        for(m=0;m<M;m++)
        {
            QCoreApplication::processEvents();
            if(m > (state+deltaProgression) )
            {
                emit progressionSignal((int)m);
                state = m;
            }


            somme = 0;
            for(k=0;k<M;k++)
            {
                /* Calcul du facteur w */
                if(k==1)
                {
                    w = 1/sqrt(M);
                }
                else
                {
                    w = sqrt(2/M);
                }

                somme = somme + w*Yin[k]*cos(M_PI*(2*m-1)*(k)/(2*M+1));
            }
            /* Remplissage du vecteur contenant la IDCT */
            Yout.push_back(somme);
        }
    }
    emit progressionSignal(100);
}
