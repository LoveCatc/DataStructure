#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 20

#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef int ElemType;
typedef struct SqStack{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

// 初始化栈
Status Init(SqStack *S){
    S->base = (ElemType *)calloc(MAXSIZE, sizeof(ElemType));
    if (!S->base) return OVERFLOW;
    S->top = S->base;
    S->stacksize = MAXSIZE;
    return OK;
}

// 销毁栈
Status Destroy(SqStack *S){
    S->top = NULL;
    free(S->base);
    S->base = NULL;
    S->stacksize = 0;
    return OK;
}

// 清空栈
Status Clear(SqStack *S){
    if (!S->base) return ERROR;
    S->top = S->base;
    return OK;
}

// 获取栈长
int StackLength(SqStack *S){
    if (!S->base) return ERROR;
    return (S->top - S->base);  // Attention!
}

// 返回栈顶元素
Status GetTop(SqStack *S, ElemType *e){
    if (!S->base) return ERROR;
    *e = *(S->top-1); return OK;
}

// 压入一个元素
Status Push(SqStack *S, ElemType e){
    if (!S->base) return ERROR;
    if ((S->top - S->base) == MAXSIZE) return OVERFLOW;
    *(S->top) = e; S->top++; return OK;
}

// 弹出一个元素
Status Pop(SqStack *S, ElemType *e){
    if (!S->base) return ERROR;
    if (S->top == S->base) return OVERFLOW;
    S->top--; 
    *e = *(S->top); 
    return OK; 
}
