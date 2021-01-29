#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>

typedef int Status;

typedef struct{
    char elem_name[10];
    float elem_value;
}ElemType;

typedef struct{
    ElemType *base_addr;
    int length;
}SqList;

Status CreateSqList(SqList L){
    L.base_addr = (ElemType *)calloc(MAXSIZE, sizeof(ElemType));
    if (!L.base_addr) return OVERFLOW;
    L.length = 0;
    return OK;
}

Status GetElem(SqList L, int i, ElemType e){
    if (i<1 || i>L.length) return ERROR;
    e = L.base_addr[i-1];
    return OK;
}

