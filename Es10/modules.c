#include "modules.h"
#include <stdio.h>
#include <stdlib.h>
typedef enum {false,true} Boolean;
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
        case '2':showList(L);break; //r
        case '3': //r
        {
            printf("Inserire valore da cercare nella lista\n");
            int n;
	    int found;
            scanf(" %d",&n);
            found=memberList(n,L);
	    if(found==1)
		printf("Elemento trovato\n");
	    else
		printf("Elemento non trovato\n");
        break;
        }
        case '4': //r
        {
            int somma=0;
            somma=sumList(L);
            printf("La somma dei valori della lista è %d\n",somma);
            break;
        }
        case '5': //r
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
    if(elem->next==NULL)
    {
        return 1;
    }
    else {
        return lengthList(elem->next)+1;
    }



}
int sumList(list L)
{
    item* elem=L;

    if(elem->next==NULL)
    {
        return elem->value;
    }
    else
    {
        return sumList(elem->next)+elem->value;
    }

}


int  memberList(int n, list L)
{ 
   item* elem=L;
//se si è arrivati alla fine non è stato trovato il valore cercato	   
    
    if(elem->value != n)
    {
        if(elem->next==NULL)
        {
            return 0;
	    }
        else {
            return memberList(n,elem->next);
        }
            
    }
    else
    {
	return 1;
    }

}

void showList(list L)
{
    //iterativa
    //faccio finta di non conoscere la lunghezza
    
   item* elem=L;
   
   if(elem!=NULL)
   {
    printf("Elemento %d",elem->value);
    showList(elem->next);
   }
    
    
}


list cons(int n,list L)
{
//la malloc di base ritorna un puntatore a void senza cast
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
