typedef struct list_element{ 
//list element è un tag  necessario perché i nomi degli struct non sono auto-referenziabili
    int value;
	//puntatore ad un prossimo "item"
    struct list_element* next;
} item;

typedef item* list; //TIPO e NON  variabile, è sbagliato scrivere solo item* List;
//nei file di header bisogna costruire i tipi di dato astratti che si intende usare nel codice dei
//file .c in cui viene incluso
void interface();
list cons(int n, list L);
list userInput(list L);
void showList(list L);
int  memberList(int n, list L);
int sumList(list L);
int lengthList(list L);
