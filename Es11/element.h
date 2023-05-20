#include <stdlib.h>
#include <stdio.h>


typedef enum {FALSE,TRUE} boolean;

typedef float element;



boolean isLess(element e1,element e2);
boolean isEqual(element e1, element e2);
element getElement(void);
void printElement(element e);
boolean isNull(element e);
element sumElement(element e1, element e2);