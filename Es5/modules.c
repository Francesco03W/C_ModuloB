#include <stdio.h>
int floatCompare(float *el1,float *el2)
{
    if(*el1==*el2)
    {
        return 0;
    }
    else {
        if(*el1<*el2)
            return -1;
        else
            return 1;
    }
}

void printFloatArray(float *array,int size)
{
    printf("L'array è:  ");
    for (int i=0; i<size; i++) 
    {
        printf("%f\n",array[i]);
    }

}
