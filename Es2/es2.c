//realizzare un programma C che, dato come argomento il nome di un file di test,o
//ne visualizzi il contenuto a pagine (20 righe alla volta). Dopo la visualizzazione
//di ciascun gruppo di righe, chiedere all'utente se vuole visualizzare
//le successive 20 (o le restanti nel file se il file ha meno di 20 righe non ancora lette) o fermarsi.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dim 40

void lettura(char* nomeFile)
{
    FILE *f;
    f=fopen(nomeFile,"r");
    if(f==0)
    {
        printf("Errore, file non aperto");
        exit(1);
    }
    else
    {
        int scelta=1;
        int end=0;
        char parola[dim];
        
        while((end==0)&&(scelta==1))
        {
            for (int i = 0; i < 20; i++)
            {
                if(fscanf(f,"%s",parola)!=EOF)
                {
                    printf("%s ",parola);
                }
                else
                {
                    end=1;
                }

            }
            printf("\nInserire 1 per stampare altre 20 righe\n");
                scanf("%d",&scelta);
        }
        fclose(f);
    }
}



int main(int argc, char** argv)
{
    if(argc!=2)
    {
        //non è stato inserito alcun argomento oltre al nome dell'eseguibile
        exit(1);
    }
    else
    {
        char nomeFile[dim];
        strcpy(nomeFile,argv[1]);

        printf("%s \n",nomeFile);

        lettura(nomeFile);
    }
    return 0;
}