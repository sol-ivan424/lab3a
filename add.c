#include "func.h"

int insert(Table* tmp){
    char* info;
    int key;
    info = readline("Enter info for add: ");
    key = hash(info);
    int p=find(tmp, key);

    if(p>=0){
        free(info);
        return 1;
    }
    int i=tmp->len;
    tmp->vect[i].info = (char *) malloc(sizeof(char)*(strlen(info)+1));
    memcpy(tmp->vect[i].info, info, sizeof(char)*(strlen(info)+1));
    tmp->vect[i].key = key;
    tmp->vect[i].busy = 1;
    ++(tmp->len);
    free(info);
    return 0;
}

int Add(Table* tmp){
    int key, res;
    tmp->vect = (Node *) realloc(tmp->vect, (tmp->len + 1)*sizeof(Node));
    res = insert(tmp);
    printf("%s: %d\n", errmsgs[res], tmp->vect[tmp->len-1].key);
    return 1;
}
