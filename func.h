#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    int busy;
    char* info;
}Node;

typedef struct Table{
    int len;
    Node* vect;
}Table;

const char* msgs[6] ;
const char* errmsgs[2] ;
const int NMsgs ;

int dialog(const char* msgs[], int s);
int getInt(int* a);
int hash(char* info);
int find(Table* tmp, int c);
int insert(Table* tmp);
int Add(Table* tmp);
int Del(Table* tmp);
int Show(Table* tmp);
int Find(Table* tmp);
int Clear(Table* tmp);
void Free(Table* tmp);

