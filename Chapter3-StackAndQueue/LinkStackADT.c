#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef int ElemType;
typedef struct LinkStack{
    ElemType elem;
    struct LinkStack *next;
}LinkStack, Node;

// 每个栈用一个**指向栈顶**的指针标识

// 初始化栈
Status Init(LinkStack *H){
    H = (LinkStack *)calloc(1, sizeof(Node));
    if (!H) return OVERFLOW; H->next = NULL;
    return OK;
}

// 销毁栈
Status Destroy(LinkStack *H){
    if (!H) return OK; Node *p = H;
    while (p){
        p = H->next;
        free(H);
        H = p;
    }
    return OK;
}

// 清空栈
Status Clear(LinkStack *H){
    if (!H) return ERROR;
    if (!H->next) return OK;
    Destroy(H->next); 
    H->next = NULL; return OK;
}

// 获取栈长
int StackLength(LinkStack *H){
    if (!H) return ERROR;
    int j = 0; Node *p = H->next;
    while (p){
        p = p->next;
        j++;
    }
    return j;
}

// 压入
Status Push(LinkStack *H, ElemType e){
    if (!H) return ERROR;
    Node *p = (Node *)calloc(1, sizeof(Node));
    p->next = H->next; H->next = p;
    p->elem = e; return OK;
}

// 弹出
Status Pop(LinkStack *H, ElemType e){
    if (!H || !H->next) return ERROR;
    e = H->next->elem;
    H = H->next; return OK;
}