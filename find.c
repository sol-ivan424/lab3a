#include "func.h"

int find(Table* tmp, int key){
    int x=0, y=tmp->len-1;
    while (x<=y){
        if ((tmp->vect[x].key == key) && (tmp->vect[x].busy == 1))
        return x;
        x++;
    }
    return -1;
}

int Find(Table *tmp){
    int key, p, q;

    printf("Enter key for find: \n");
    p=getInt(&key);
    if(p == 0)
    return 0;

    q=find(tmp, key);
    if ((q>=0) && (tmp->vect[q].busy == 1))
    printf("key = %d | info : %s\n", key, tmp->vect[q].info);
    else
    printf("Item %d was not found\n", key);
    return 1;
}
