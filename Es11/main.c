
#include "tree.h"




//bisogna impostare il task json per debug



int main()
{
	tree T=NULL;

	boolean menuexit=FALSE;
	while(menuexit==FALSE)
	{
		printf("Scegliere l'operazione da eseguire\n");
		printf("0 per uscire, 1 per inserire un valori nel nodo\n"
				"2 per preorder,3 postorder,4 inorder, 5 ricerca, 6 altezza albero\n"
				"7 somma valori albero 8 conteggio nodi albero, 9 calcolo bilanciamento albero\n");
		int choice;
		scanf("\n%d",&choice);

		switch (choice) {
			case '0':
			menuexit=TRUE;
			break;
			case 1:
			{
				char scelta='n';
				element el;
				while(scelta!='y')
				{
					el=getElement();
					T=ord_ins(el,T);
					printf(" terminare l'inserimento? y/n\n");
					scanf(" %c",&scelta);
				}
				break;
			}
			
			case 2:
			{
				preorder(T);
				break;
			
			}
			case 3:
				postorder(T);
				break;
			case 4:
				inorder(T);
				break;
			case 5:
			{
				printf("inserire valore da cercare nell'albero\n");
				element val;
				scanf(" %f",&val);
				boolean found;
				found=member(val,T);
				if(found==TRUE)
					printf("valore trovato\n");
				else
					printf("valore non trovato\n");
			break;
			}
			
			case 6:
			{
				int h=height(T);
				printf("altezza albero= %d\n",h);
				break;
			}	
			
			case 7:
			{
				element s=sum(T);
				printf("Somma valori albero= %f\n",s);
				break;
			}
			
			case 8:
			{
				int num=nnodes(T);
				printf("numero nodi %d\n",num);
				break;
			}
			case 9:
			{
				int balanced=balance(T);
				printf("Il bilanciamento dell'albero è %d\n",balanced);
				break;
			}
		}

	}
}

