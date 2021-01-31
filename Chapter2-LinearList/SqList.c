#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int LocateElem(SqList L, ElemType e){
    int i;
    for (i=0; i<L.length; i++){
        if (!(strcmp(L.base_addr[i-1].elem_name, e.elem_name)) && L.base_addr[i].elem_value == e.elem_value) return i+1;
    }
    return 0;
}

Status InsertElem(SqList L, int i, ElemType e){
    if (i<1 || i>(L.length+1)) return ERROR;
    if (L.length == MAXSIZE) return OVERFLOW;
    int j;
    for (j=L.length-1; j>=i; j--){
        L.base_addr[j+1] = L.base_addr[j];
    }
    L.base_addr[i-1] = e;
    L.length++;
    return OK;
}

Status DeleteElem(SqList L, int i){
    if (i<1 || i>L.length) return ERROR;
    int j;
    for (j=i; j<L.length; j++){
        L.base_addr[j-1] = L.base_addr[j];
    }
    L.length--;
    return OK;
}
