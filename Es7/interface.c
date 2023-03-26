
#include "interface.h"
#include <stdlib.h>
#include <string.h>

//funzione di compare per ordinare la tabella rispetto a cognome e nome, sempre per cognome, e se due cognomi sono uguali allora per nome
//gli argomenti di keycompare sono puntatori a puntatori
int keyCompare(const void *el1, const void *el2)
{
    Contatto c1,c2;
    // el1/2 viene dereferenziato a puntatore a "contatto" e a sua volta
    // dereferenziato al contenuto della memoria puntata da quest'ultimo
    c1=*(Contatto*)el1;
    c2=*(Contatto*)el2; 
    int compare=strcmp(c1.cognome,c2.cognome);
    if(compare!=0)
    {
        return compare;
    }
    else
    {
        return strcmp(c1.nome,c2.nome);
    }
}


void printTable(TavolaContatti tavola,int logicindex)
{
    if(logicindex==0)
    {printf("Non ci sono elementi nella rubrica\n");
    }
    else 
    {
        //stampa la tabella, è un array di struct
        for (int i=0; i<logicindex; i++) 
        {
            printf("Contatto %d :\n",i+1);
            printf("nome: %s\n ,cognome:%s\n ,telefono: %lli\n -----------\n",tavola[i].nome,tavola[i].cognome,tavola[i].num_telefono);
        }
    }
}

void insertContactInTable(TavolaContatti tavola,int *logicindex)
{
    char nome[20];
    char cognome[20]; 
    long long int numero;
    printf("....inserimento...\n");
    printf("inserire nome contatto\n");
    scanf("%s",nome);
    printf("Inserire cognome contatto\n");
    scanf("%s",cognome);
    printf("Inserire numero di telefono\n");
    scanf("%lli",&numero);

    //inserimento in tavola
    strcpy(tavola[*logicindex].nome,nome);
    strcpy(tavola[*logicindex].cognome,cognome);
    tavola[*logicindex].num_telefono=numero;

    (*logicindex)++;
    qsort(tavola,*logicindex,sizeof(Contatto),keyCompare);

}