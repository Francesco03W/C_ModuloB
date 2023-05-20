#include "tree.h"

tree cons_tree(element e,tree l, tree r)
{
    NODO* t=(NODO*)malloc(sizeof(NODO));
    t->value=e;
    t->left=l;
    t->right=r;
    return t;
}


//inserimento ordinato ricorsivo
/*
tree ord_ins(elemento e,tree t)
{
    if(t==NULL)
        return cons_tree(e,NULL,NULL);
    else
    {
        if(e<=t->value)
            t->left=ord_ins(e,t->left);
        else
            t->right=ord_ins(e,t->right);
        
        return t;
    }

}

*/

//iterativo
tree ord_ins(element e,tree t)
{   
    tree root=t;
    tree p; //nodo padre
    //se l'albero è vuoto
    if(root==NULL)
    {
        return cons_tree(e,NULL,NULL);
    }
    else {
        //continuo finchè non raggiungo un padre con figli vuoti
        //finché il nodo è diverso da foglia
        while(t!=NULL)
        {
            p=t; //salvo il nodo padre poi scendo ai figli
            if(e<=t->value)
            {
                t=t->left;
            }
            else {
                t=t->right;
            }
            
        }
        //una volta che n raggiunge una foglia nulla significa che sono a destinazione 
        //cioè sono ad un padre p che ha il figlio NULL su cui porre e
        if(e<=p->value)
        {
            p->left=cons_tree(e,NULL,NULL);
        }
        else {
            p->right=cons_tree(e,NULL,NULL);
        }
    }
    return root;
}

void preorder(tree t)
{// esiste solo ricorsiva
    if(t!=NULL)
    {
        printf("valore nodo %f\n",t->value);
        preorder(t->left);
        preorder(t->right);
    }

}

void postorder(tree t)
{
    if(t!=NULL)
    {
        preorder(t->left);
        preorder(t->right);
        printf("valore nodo %f\n",t->value);
    }
}

void inorder(tree t)
{
    if(t!=NULL)
    {
        preorder(t->left);
        printf("valore nodo %f\n",t->value);
        preorder(t->right);
    }
}

/*
member ricorsiva
boolean member(element e, tree t)
{
    if(t==NULL)
    {
        return false;
    }
    else
    {
        if(e==t->value)
        {
            return TRUE;
        }
        else
        {
            if(e<t->value)
                return member(e,t->left);
            else
                return member(e,t->right);
        }
    }
}

*/
boolean member(element e,tree t)
{
    boolean trovato=FALSE;
    while(t!=NULL && !trovato)
    {
        if(e==t->value)
        {
            trovato=TRUE;
        }
        else {
        if(e>t->value)
            t=t->right;
        else
         t=t->left;
        }
    }
    return trovato;
}


//tre funzioni per calcolare altezza dell'albero
int mymax(int v1,int v2)
{
    if(v1>=v2)
        return v1;
    else 
    {
       return v2;
    }

}
int height_aux(tree t)
{
    if(t==NULL)
    {
        return 0;
    }
    else {
        return (1+ mymax(height_aux(t->left),height_aux(t->right)));
    }
}
int height(tree t)
{
    if(t!=NULL)
    {
        return mymax(height_aux(t->left),height_aux(t->right));
    }
    else {
    return 0;
    }

}
int nnodes(tree t)
{
    if(t==NULL)
        return 0;
    else
    {
        return 1+nnodes(t->left)+nnodes(t->right);
    }
}

//esegue la somma dei valori dell'albero
element sum(tree t)
{
    if(t==NULL)
        return 0;
    else
    {
        return t->value + sum(t->left) + sum(t->right);
    }
}

//albero bilanciato se gli elementi sono distribuiti uniformemente nei sottoalberi
//nei BST bilanciati per ciascun nodo, l'altezza del sottoalbero sinistro e destro differiscono al 
//più di un unità.
//se un albero non è bilanciato può degenerare in una lista (caso peggiore per ricerche O(n))
//se bialnciato O(log2 di N)
int balance(tree t)
{
    //controllare se l'albero è bilanciato
    /*gli alberi AVL sono bilanciati, un NODO è bilanciato quando l'h dell'albero sinistro
     differisce dall'h del sotto-albero destro di al più di un'unità.
     ed un albero si dice bilanciato se TUTTI i nodi sono bilanciati
    */

    if(t==NULL)
        return 0;
    else
        return(height(t->right) - height(t->left));



}