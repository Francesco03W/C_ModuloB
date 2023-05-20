//Un file elenco.txt ha almeno 20 studenti, si scriva una funzione (funzioneAB) che carica i soli nomi
//dei primi 20 studenti in un array V di 20 stringhe (ognuna al massimo di 50char)
//la funzione riceve come parametri il vettore V e il puntatore al file elenco1.txt e restituisce void
//nel main si ordini il vettore V attraverso una chiamata della funzione qsort e poi si stampi il contenuto in un file outputAB.txt


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prendo tutto in array di struct per poi mettere i nomi nell'array di stringhe V
typedef struct
{
    char nome[50];
    char cognome[50];
}studente;

typedef studente studenti[20]; //studenti è un array di 20 struct
typedef char nome[50]; //singola stringa (oggetto dell'array)


//per ordinare l'array di stringhe V
int compare(const void *el1, const void *el2)
{
    //ora dereferenzio el1 ed el2, che sono due puntatori ai puntatori degli elementi da confrontare
    /* ATTENZIONE QUESTO NON SI PUO' FARE PERCHE' LE STRINGHE NON SI ASSEGNANO (ogni tipo nome è un char[50])-> 
    nome nome1= *(nome*)el1;
    nome nome2= *(nome*)el2;
    
    */
    nome nome1;
    nome nome2;
    strcpy(nome1,*(nome*)el1);
    strcpy(nome2,*(nome*)el2);
    
    return strcmp(nome1,nome2); //confronto le due stringhe
}

FILE* openFile(char* nomeFile,char* mode)
{
    FILE* fd=fopen(nomeFile,mode);
    if(fd==NULL)
    {
        printf("apertura file non riuscita\n");
        exit(1);
    }
    return fd;
}

//ATTENZIONE studenti non ha bisogno di * perché studenti indica già un'array,
// mentre V è un array di nomi, quindi un array di stringhe
void funzioneAB(studenti S,nome* V,FILE* fd)
{
    fd=openFile("elenco1.txt","r");
    int num=0;
    //allora, il problema è che il controllo num<20 lo fa dopo aver inserito il valore nell'indice 21 che infatti NON ESISTE
    for (int i = 0; i < 20; i++)
    {
        fscanf(fd,"%s %s",S[i].nome,S[i].cognome);
        strcpy(V[i],S[i].nome);
    }
    fclose(fd);
}


int main()
{
    nome V[20]; //array di stringhe, ovvero 20 stringhe da 50 dimensione massima
    studenti S; //è come dire studente[20]
    
    FILE* fd;

    funzioneAB(S,V,fd);

    //qsort degli elementi dell'array di stringhe
    qsort(V,20,sizeof(nome),compare);

    //stampa in file outputAB.txt
    
    fd=openFile("outputAB.txt","w");
    for (int i = 0; i < 20; i++)
    {
        fprintf(fd,"%s\n",V[i]);
    }
   
    fclose(fd);
    return 0;
}

