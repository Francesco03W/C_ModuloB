#include <stdio.h>


typedef enum{true,false} Boolean;

void insert(int *array, int logicindex, int number)
{
    
    //cerco lo spazio giusto per il valore scorrendo l'array LINEARMENTE
    
    
    int index=0;
    if(logicindex==1) //primo valore con indice 0
        array[index]=number;
    else
    {
        Boolean placed=false;
        while(placed==false && index<logicindex)
        {
            if(number<array[index])
            {
                //scorro l'array a destra da index in poi per fare spazio al valore 
                for (int j=logicindex; j>index; j--) {
                    array[j]=array[j-1];
                }
                placed=true;
                array[index]=number;
            }
            else {
                if(index==logicindex-1)
                {
                    //significa che non ha trovato un valore minore tra tutti quanti, quindi si assegna alla fine (caso peggiore)
                    array[index]=number;
                }
                else {
                
                index++;
            
                }
            }
        }
    }
}
