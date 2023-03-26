
typedef struct{
    char nome[20];
    char cognome[20];
    long long int num_telefono; //un int non può contenere tutte le cifre di un numero telefonico
} Contatto;

typedef Contatto TavolaContatti[100];

void printTable(TavolaContatti tavola ,int logicindex);
void insertContactInTable(TavolaContatti tavola, int *logicindex);