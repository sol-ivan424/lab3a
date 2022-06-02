#include "func.h"

int Clear(Table* tmp){
    int x, y = tmp->len;
    for(x=0;x<y;x++){
        if(tmp->vect[x].busy == 0){
            int n;
            for (n=x;n<y-1;n++){
                free(tmp->vect[n].info);
                tmp->vect[n].info = (char *) malloc(sizeof(char)*(strlen(tmp->vect[n+1].info)+1));
                memcpy(tmp->vect[n].info, tmp->vect[n+1].info, sizeof(char)*(strlen(tmp->vect[n+1].info)+1));
                tmp->vect[n].key = tmp->vect[n+1].key;
                tmp->vect[n].busy = tmp->vect[n+1].busy;
            }
            free(tmp->vect[n].info);
            --y;
            --(tmp->len);
        }
    }
    printf("Table was cleaned!\n");
    return 1;
}
