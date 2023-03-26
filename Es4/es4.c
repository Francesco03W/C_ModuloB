/*
Si realizzi un componente dotato di stato interno che rappresenta un contatore, con operazioni:
void reset(void)
void inc(int k)
int getValue(void)
Il main, che utilizza il contatore, deve in successione:
- resettare il contatore (porlo a 0)
- acquisire da tastiera una sequenza di interi positivi (terminata da 0) e usarli come incremento del contatore
- stampare lo stato finale
La variabile contatore deve essere globale, locale al file contenente le funzioni del contatore (e protetta ovvero static).
Strutturare il programma su più file.
*/
#include <stdio.h>
#include "contatore.h"

extern int value; //global

int main()
{
    
    reset();
    for (int i = 0; i < 20; i++)
    {
        inc(1);
    }
    
    printf("%d \n",getValue());



    return 0;
}


