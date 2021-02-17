#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef int ElemType;
typedef struct SqQueue{
    int front;
    int rear;
    ElemType elem[MAXSIZE];
}SqQueue;

Status Init(SqQueue *Q){
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

int QueueLength(SqQueue *Q){
    return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue *Q, ElemType e){
    // if (Q->rear+1)%MAXSIZE == Q->front
    if (QueueLength(Q) == MAXSIZE-1) return OVERFLOW; 
    Q->elem[Q->rear] = e; 
    Q->rear = (Q->rear+1)%MAXSIZE; // Attention!
    return OK;
}

Status DeQueue(SqQueue *Q, ElemType *e){
    if (QueueLength(Q) == 0) return ERROR;
    *e = Q->elem[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return OK;
}

ElemType GetFront(SqQueue *Q){
    return Q->elem[Q->front];
}