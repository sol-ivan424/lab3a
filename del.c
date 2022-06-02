#include "func.h"

int Del(Table *tmp){
    int key, s, z;

    printf("Enter key for delete: \n");
    s = getInt(&key);
    if(s == 0)
    return 0;

    z = find(tmp, key);
    if (z >= 0){
        tmp->vect[z].busy = 0;
        printf("Item %d was successfully deleted\n", key);
    }else{
        printf("Item %d was not found\n", key);
    }
    return 1;
}
