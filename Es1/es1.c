//Si realizzi il programma che calcola la somma di una funzione reale di una variabile reale
// in un intervallo dato [a,b]

//Chiamare da main tale funzionale, passandogli ogni volta una funzione matematica, di libreria, o definite
//da un programma, (ad esempio seno e coseno, funzione reciproco,ecc) stampando il valore a video

#include <math.h>
#include <stdio.h>

double cubo(double x)
{
    return (x*x*x);
}

double sommatoria(double (*funct)(double),int a,int b)
{
    double somma=0;
    for (int i = a; i <= b; i++)
    {
        somma+=(*funct)(i);
    }
    return somma;    
}


int main()
{
    double val;
    val=sommatoria(cubo,1,5);
    printf("Il risultato della sommatoria di x^3 da 1 a 5 è: %f \n",val);

    return 0;
}