
typedef struct{
    char nome[20];
    char cognome[20];
    long long int num_telefono; //un int non può contenere tutte le cifre di un numero telefonico
} Contatto;

//tipo di dato astratto "TavolaContatti", cioè un array di 100 "Contatto"
typedef Contatto TavolaContatti[100];

void printTable(TavolaContatti tavola ,int logicindex);

void insertContactInTable(TavolaContatti tavola, int *logicindex);

//la findcontact deve ritornare uno status per sapere se si può cancellare il contatto o meno
int findContact(TavolaContatti tavola, int logicindex);
