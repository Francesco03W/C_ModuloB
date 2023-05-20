#include <stdio.h>
#include <stdlib.h>
#define dim 200

#include "modules.h"

// typedef float ELEMENT;
typedef enum {false,true} Boolean;

int main()
{
    float vettore[dim];
    int logicindex=0;
    Boolean input;
    int close;

    while(input==true)
    {
        printf("inserire numero reale");
        scanf("%f",&vettore[logicindex]);
        
        logicindex++;

        printf("inserire un altro numero? Inserire 1, Altrimenti, inserire 0 ");
        scanf(" %d",&close);
        
        if(close==0)
        {
            input=false;
        }
    }
    
    qsort(vettore,logicindex,sizeof(float),floatCompare);
    
    printFloatArray(vettore,logicindex);


    return 0;
}
