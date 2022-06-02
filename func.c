#include "func.h"

const char* errmsgs[] = {"Ok", "Duplicate key"};

int getInt(int *a){
    int r;
    do{
        r = scanf("%d", a);
        if (r<0){
            return 0;
        }
        if (r == 0){
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (r == 0);
    return 1;
}

int hash(char *info){
    int key, x, y=strlen(info), z=0;
    for(x=0;x<y; x++)
    z=z+info[x];
    key = z % 100;
    return key;
}

void Free(Table* tmp){
    int x , y=tmp->len;
    for (x=0; x<y; x++){
        free(tmp->vect[x].info);
    }
    free(tmp->vect);
    free(tmp);
}

int Show(Table *tmp){
    int x, y = (tmp->len);
    for (x=0;x<y; x++){
        if (tmp->vect[x].busy)
        printf("key = %d | info : %s\n", tmp->vect[x].key, tmp->vect[x].info);
    }
    return 1;
}

int dialog(const char* msgs[], int s){
    char* errmsg = "";
    int ch,x,y;
    for(x=0; x<s; ++x){
        puts(msgs[x]);
    }
    do{
        puts(errmsg);
        errmsg = "You are wrong. Repeate, please!";
        puts("Make your choice: ");
        y = getInt(&ch);
        if(y == 0)
        ch=0;
    } while(ch<0 || ch>=s);
    return ch;
}
