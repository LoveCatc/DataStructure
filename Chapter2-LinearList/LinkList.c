#define OK 1
#define ERROR 0
#define OVERFLOW -2

#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef struct{
    int value;
}ElemType;
typedef struct ListNode{
    ElemType data;
    struct ListNode *next;
}ListNode;

Status CreateList(ListNode *L){
    L = (ListNode *)calloc(1, sizeof(ListNode));
    L->next = NULL;
    return OK;
}

Status GetElem(ListNode *L, int i, ElemType e){
    int j=1;
    ListNode *p = L->next;
    while (j<i && p){
        p = p->next;
        j++;
    }
    if (j>i || !p) return ERROR;
    e = p->data;
    return OK;
}

Status LocateElem(ListNode *L, int i, ElemType e){
    ListNode *p = L;
    int j=0;
    while(p->data.value != e.value){
        j++;
        p = p->next;
    }
    i = j;
    return OK;
}

Status InsertElem(ListNode *L, int i, ElemType e){
    ListNode *p = L;
    int j=0;
    while (j<i-1 && p){
        j++;
        p = p->next;
    }
    if (j>i-1 || !p) return ERROR;

    ListNode *new_node = (ListNode *)calloc(1, sizeof(ListNode));
    new_node->next = p->next;
    p->next = new_node;
    new_node->data = e;
    return OK;
}

Status CreateListH(ListNode *L, int n){
    L = (ListNode *)calloc(1, sizeof(ListNode));
    int i;
    for (i=0; i<n; i++){
        ListNode *new_node = (ListNode *)calloc(1, sizeof(ListNode));
        new_node->next = L->next;
        L->next = new_node;
    }
    return OK;
}

Status CreateListR(ListNode *L, int n){
    L = (ListNode *)calloc(1, sizeof(ListNode));
    int i;
    ListNode *r = L;    //r points to the last node
    for (i=0; i<n; i++){
        ListNode *new_node = (ListNode *)calloc(1, sizeof(ListNode));
        r->next = new_node;
        new_node->next = NULL;
    }
    return OK;
}