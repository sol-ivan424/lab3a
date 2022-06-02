#include "func.h"

const char* msgs[] = {"0. Quit", "1. Add", "2. Delete", "3. Show", "4. Find", "5. Clear"};
const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

int main(){
    Table* table = NULL;
    table = (Table *) calloc(1, sizeof(Table));
    int choice;
    int (*fptr[])(Table *) = {NULL, Add, Del, Show, Find, Clear};
    while(choice = dialog(msgs, NMsgs)){
        if(!fptr[choice](table))
        break;
    }
    printf("That's all. Bye!\n");
    Free(table);
    return 0;
}
