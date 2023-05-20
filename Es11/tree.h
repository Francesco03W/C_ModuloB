#include "element.h"


typedef struct nodo 
{
	element value;
	struct nodo *left,*right;
} NODO;

typedef NODO* tree;

 tree ord_ins ( element , tree );
 void preorder ( tree ) ;
 void postorder ( tree ) ;
 void inorder ( tree ) ;
 boolean member ( element , tree ) ;
 int height ( tree ) ;
 element sum ( tree ) ;
 int nnodes ( tree ) ;
 int balance ( tree ) ;