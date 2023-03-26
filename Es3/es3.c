//si realizzi un programma che calcola la somma e la media di una funzione f: R->R in un intervallo dato [a,b]
//definire una funzione sommaf che restituisca il valore della sommatoria con la seguente interfaccia:
/* double sommaf(double(*f)(double par),int m, int n)
dove f è la funzione matematica di cui calcolare la sommatoria,a e b gli estremi dell'intervallo. Definire poi una funzione mediaf
che restituisca il valore della media con la seguente interfaccia: double mediaf(double (*f)(double par),int m, int n)
*/
#include <stdio.h>


double quadrato(double x)
{
    return (x*x);
}

double sommaf(double(*f)(double par),int m, int n)
{
//sommatoria
    double sum;
    for ( int i = m; i <= n; i++)
    {
        sum+=(*f)(i);
    }
    
    return sum;
}

double mediaf(double (*f)(double par),int m,int n)
{
    int num;
    double avg;
    double sum;
    for (int i = m; i <= n; i++)
    {
        sum+=(*f)(i);
        num++;
    }
    avg=sum/num;
    return avg;
}


int main()
{
    double somma;
    double media;
    somma=sommaf(quadrato,1,2);
    printf("%f \n",somma);

    media=mediaf(quadrato,1,2);
    printf("%f \n",media);
    return 0;
}





