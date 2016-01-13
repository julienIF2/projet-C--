#include "transform.h"

Transform::Transform()
{

}

Transform::~Transform()
{
    // TODO free les vector
    dataOutY.clear();
    dataOutX.clear();
}

void Transform::dctTransform(void)
{
   double somme;
   double k,j,N,w;
   double Fe;

   /* Récupération de la taille du signal d'entrée */
   N = dataInX.size();
   /* Remise à l'état initial des vecteurs */
   dataOutY.clear();
   dataOutX.clear();

   /* Calcul des valeurs de l'axe X */
   Fe = 1/(dataInX[1]-dataInX[0]);
   for(k=0;k<N;k++)
   {
       dataOutX.push_front(Fe/2*k/N);
   }

   for(k=0;k<N;k++)
   {
       /* Calcul de la somme des N valeur */
       somme = 0;
       for(j=0;j<N;j++)
       {
           somme = somme + dataInY[j]*cos(M_PI/(2*N)*(2*j)*k);
       }
       /* Calcul du facteur w */
       if(k==1)
       {
           w = 1/sqrt((double)N);
       }
       else
       {
           w = sqrt(2/(double)N);
       }
       /* Remplissage du vecteur contenant la DCT */
       dataOutY.push_front(w*somme);
   }
}

void Transform::idctTransform(void)
{
    double somme;
    double m,k,M,w;
    double deltaT;

    /* Récupération de la taille du signal d'entrée */
    M = dataInY.size();

    /* Remise à l'état initial des vecteurs */
    dataOutY.clear();
    dataOutX.clear();

    /* Calcul des valeurs de l'axe X */
    deltaT = 1/(dataInX[1]-dataInX[0]);
    for(k=0;k<M;k++)
    {
        dataOutX.push_front(deltaT*k/M);
    }

    for(m=0;m<M;m++)
    {
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

            somme = somme + w*dataInY[k]*cos(M_PI*(2*m-1)*(k)/(2*M+1));
        }
        /* Remplissage du vecteur contenant la IDCT */
        dataOutY.push_front(somme);
    }
}

void Transform::startDCT(void)
{
    // TODO vérifier les data avant de lancer l'opération

    this->dctTransform();
}

void Transform::startDCT(void)
{
    // TODO vérifier les data avant de lancer l'opération

    this->idctTransform();
}
