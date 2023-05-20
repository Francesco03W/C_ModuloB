#include <stdio.h>
#define dim 30
#include "insert.h"

typedef enum {false,true} Boolean;

// USO UNA RICERCA LINEARE DELL'ARRAY, DATO CHE SI TRATTA DI UN ARRAY DI PICCOLE DIMENSIONI
void printIntArray(int* array,int logicindex)
{
    printf("\nL'array è formato dai seguenti elementi:\n");
    for (int i=0; i<logicindex ; i++) {
        printf("index: %d-> %d \n",i,array[i]);
    }
}


int main()
{

    int array[dim];

    int logicindex=0;
    Boolean input;
    int close,value;
    while(input==true && logicindex!=dim)
    {

        printf("inserire numero intero\n");
        scanf("%d",&value);
        
          
        logicindex++;
        insert(array,logicindex,value);
        
        
        printIntArray(array, logicindex);   
        

        


        printf("inserire un altro numero? Inserire 1, Altrimenti, inserire 0 ");
        scanf(" %d",&close);
        
        if(close==0)
            input=false;
        
    }
    if(logicindex==dim)
    {
        printf("non c'è più spazio nell'array\n");
    }


    return 0;
}

