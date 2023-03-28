#include "modules.h"
#include <stdio.h>
#include <stdlib.h>

void interface()
{
    Boolean close=false;
    list L=NULL;
    while(close==false)
    {
    
    printf("Scegliere operazione\n");
    printf("Inserire 1 per creazione lista di valori\n");
    printf("inserire 2 per mostrare la lista\n");
    printf("inserire 3 per cercare un elemento nella lista\n");
    printf("inserire 4 per sommare i valori della lista\n");
    printf("inserire 5 per contare i valori nella lista\n");
    printf("inserire 0 per chiudere\n");
    printf("----------------------------\n");
    char scelta;
    scanf(" %c",&scelta);
    switch(scelta)
    {
        case '0':
        {
            close=true;
            break;
        }
        case '1':
        {
            L=userInput(L); 
            break;
        }
        case '2':showList(L);break;
        case '3':
        {
            printf("Inserire valore da cercare nella lista\n");
            int n;
            scanf(" %d",&n);
            memberList(n,L);
            break;
        }
        case '4':
        {
            int somma=0;
            somma=sumList(L);
            printf("La somma dei valori della lista è %d\n",somma);
            break;
        }
        case '5':
        {
            int count=0;
            count=lengthList(L);
            printf("Il numero di elementi della lista è %d\n",count);
            break;
        }
     }   
    }
}
int lengthList(list L)
{
    item* elem=L;
    int count=0;
    while(elem!=NULL)
    {
        count++;
        elem=elem->next;
    }
    return count;
}
int sumList(list L)
{
    item* elem=L;
    int sum=0;
    while(elem!=NULL) //se non ci sono elementi ritorna 0
    {
        sum=sum+elem->value;
        elem=elem->next; //scorro elemento succ
    }
    return sum;
}

void memberList(int n, list L)
{ 
        while(L!=NULL)
        {
            if(L->value==n)
            return 1;
            else
                L=L->next;
            return 0;
        }

}

void showList(list L)
{
    //iterativa
    //faccio finta di non conoscere la lunghezza
    
    item* elem=L; //parto dal primo elemento
    while(elem!=NULL)
    {
        printf(" val:%d -",elem->value);
        elem=elem->next;
    }
    printf("\n");
}


list cons(int n,list L)
{
    list aux=(list) malloc(sizeof(item)); //list è item*
    aux->value=n;
    //vers iterativa
    // che la lista sia vuota non cambia nulla
    aux->next=L;
    return aux;
}


list userInput(list L)
{
    printf("Inserire una sequenza di numeri terminata da 0\n");
    int num=1;
    int end=0;
    while(end==0)
    {
        printf("Inserire numero\n");
        scanf(" %d",&num);
        if(num!=0)
            L=cons(num,L);
        else
            end=1;
    }
    return L;
}