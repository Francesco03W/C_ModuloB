
#include "interface.h"
#include <stdlib.h>
#include <string.h>

int findContact(TavolaContatti tavola,int logicindex)
{
/* è sempre meglio usare un flag per uscire da una funzione così che sia chiaro il dato ritornato
posizionandolo alla fine della funzione*/
int found=0;
int cont=0;
char nome[20]; //dimensione da consegna
	printf("Inserire nome dell'utente da cercare\n");
	scanf(" %s",nome);

//dato che considero un solo contatto con il nome (da esercizio a quanto pare) allora basta un while
	while(found==0 && cont < logicindex)
	{
		if(strcmp(tavola[i].nome,nome)
		{
			found=1;
		}
		else
			cont++;
	}
	if(found==0)
	{
		printf("non è presente un contatto con questo nome\n");	
		return 0;
	}
	else
	{
		printf("Numero del contatto %s \n",tavola[i].num_telefono);
		return 1;
	}
}


//funzione di compare per ordinare la tabella rispetto a cognome e nome, sempre per cognome, e se due cognomi sono uguali allora per nome
//gli argomenti di keycompare sono puntatori a puntatori
int keyCompare(const void *el1, const void *el2)
{
    Contatto c1,c2;
    // el1/2 viene convertito  a puntatore da void  a "contatto" e a sua volta
    // dereferenziato al contenuto della memoria puntata da quest'ultimo
    c1=*(Contatto*)el1;
    c2=*(Contatto*)el2; 
    //confronto cognomi
    int compare=strcmp(c1.cognome,c2.cognome);
    if(compare!=0)
    {
        return compare;
    }
    else
    {
	//se cognomi uguali allora si confrontano i nomi
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

    //conteggio del contatto inserito
    (*logicindex)++;
    qsort(tavola,*logicindex,sizeof(Contatto),keyCompare);

}
