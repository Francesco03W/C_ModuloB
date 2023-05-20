/*realizzare una rubrica telefonica, ogni elemento è caratterizzato da:
cognome,nome,telefono.

la rubrica è una tavola inizializzata in memoria centrale ordinata sulla chiave costituita dalla coppia cognome-nome
(array ordinato in base al cognome e in caso di uguaglianza, al nome)

il programma deve consentire: 
inserimento -> Dati cognome, nome e numero di telefono della persona da inserire il programma aggiunge un nuovo elemento all'archivio,
poi riordina la rubrica (qsort) in modo da mantenerla ordinata rispetto alla chiave

stampa-> l'utente richiede la stampa dell'intera rubrica
uscita-> l'utente richiede che il programma termini

L'interazione utente è ciclica, usando uno switch.
Il programma deve essere opportunamente strutturato su più file
*/

/*cosa ho imparato:
- IMPORTANTE PER DEBUGGARE IN ESAME:  usare build per tasks.json (usa sempre workspace)
- usare la qsort, come passare i parametri e usare cast con ATTENZIONE alle stringhe
- mettere dichiarazione delle strutture/ tipi di dato astratti in file header, insieme alle dichiarazioni di funzioni

*/


#include <stdlib.h>
#include <stdio.h>
#include "interface.h" //contiene typedef struct contatto e TavolaContatti

typedef enum {false,true} Boolean; //enumeratore assegna in ordine valori da 0 a n in base all'n
// numero di possibili valori assunti dalle variabili di tipo Boolean
TavolaContatti Tavola; //array di 100 Contatti

char interface()
{
    printf("Immettere 1 per inserire un contatto,2 per stampare la rubrica, 3 per cercare un contatto in base al nome,  qualsiasi altro numero per uscire\n");
    char input;
    scanf(" %c",&input);

    return input;
}


int main()
{
    Boolean exit=false;
    int logicindex=0;
    while(exit==false)
    {
        switch(interface())
        {
            case '1':
                insertContactInTable(Tavola,&logicindex);
                printf("contatto aggiunto\n");
                break;
            case '2':
                printTable(Tavola,logicindex);
                break;
            case '3':
		findContact(Tavola,logicindex);
	   	break;
  	    default:
                exit=true;
                break;
        }
    }
    return 0;
}



