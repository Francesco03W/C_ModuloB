#include "element.h"


element getElement()
{
    element el;
    float val=-1;
        printf("inserire valore del nodo\n");
        scanf(" %f",&val);
        el=val;
        return el;
}
boolean isLess(element el1,element el2)
{
    if(el1<el2)
    {
        return TRUE;
    }
    else {
        return FALSE;
    }
}
boolean isEqual(element e1,element e2)
{
    if(e1==e2)
        return TRUE;
    else
     return FALSE;
}
void printElement(element e)
{
    printf(" %f",e);
}
boolean isNull(element e)
{
    if(e==0)
        return TRUE;
    else
     return FALSE;   
}
element sumElement(element e1,element e2)
{
    return e1+e2;
}