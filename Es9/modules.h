typedef struct list_element{
    int value;
    struct list_element* next;
} item;
typedef enum {true,false} Boolean;
typedef item* list; //TIPO non variabile, è sbagliato scrivere solo item* List;

void interface();
list cons(int n, list L);
list userInput(list L);
void showList(list L);
void memberList(int n, list L);
int sumList(list L);
int lengthList(list L);