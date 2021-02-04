#define OK 1
#define ERROR 0
#define OVERFLOW -2

#include <stdio.h>

typedef int Status;
typedef struct{
    int value;
}ElemType;
typedef struct{
    ElemType *base_attr;
    int length;   
}SqList;
typedef struct NodeList{
    ElemType e;
    struct NodeList *next;
}NodeList;

// After-class exercise 5
Status InsertSqList(SqList L, ElemType e){
    // Sqlist is empty
    if (L.length == 0){
        L.base_attr[0] = e;
        L.length++;
        return OK;
    }
    // Sqlist is not empty
    int i=0;
    while (i <= (L.length-2)){
        if ( (e.value>=L.base_attr[i].value) && (e.value<=L.base_attr[i+1].value) ){
            int j;
            for (j=L.length; j>i; j--){
                L.base_attr[j] = L.base_attr[j-1];
            }
            L.length++;
            L.base_attr[i] = e;
            return OK;
        }
    }
    // e is greater than any elem in Sqlist
    L.base_attr[L.length] = e;
    L.length++;
    return OK;
}

// After-class exercise 6
Status ListLinkListLength(NodeList *H, int c){
    // H is the head pointer of NodeList
    int i=0;
    while(H->next != NULL){
        i++;
    }
    c = i;
    return OK;
}

// After-class exercise 7
Status DeleteRepNodes(NodeList *H, NodeList *F){
    NodeList *p = H;
    NodeList *N = (NodeList *)calloc(1, sizeof(NodeList));
    N->next = NULL;
    N->e.value = H->e.value;
    while(p){
        int repeated = 0;
        NodeList *q = N;
        // whether repeated
        while (1){
            if (q->e.value == p->e.value){
                repeated = 1;
                break;
            }
            if (q->next == NULL) break;
            q = q->next;
        }
        // if not repeated, q points to the last node of N
        if (!repeated) q->next = p;
        p = p->next;
    }
    F = N;
    return OK;
}

// After-class exercise 9
Status SortTwoLinkList(NodeList *A, NodeList *B, NodeList *R){
    //
}