#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Status;
typedef int ElemType;
typedef struct Node{
    ElemType e;
    struct Node* next;
}Node, NodeList;

// 初始化单链表
Status Init(NodeList *L){
    L = (Node *)calloc(1, sizeof(Node));
    L->next = NULL;
    return OK;
}

// 销毁单链表
Status Destroy(NodeList *L){
    Node *q;
    while (L){
        q = L->next;
        free(L);
        L = q;
    }
    return OK;
}

// 清空单链表
Status Clear(NodeList *L){
    Node *q = L->next;
    Destroy(q);
    L->next = NULL;
    return OK;
}

// 求单链表长度
int Length(NodeList *L){
    int i = 0;
    Node *q = L;
    while (q->next){
        q = q->next;
        i++;
    }
    return i;
}

// 按位置索引元素
Status GetNode(NodeList *L, int i, ElemType elem){
    int j = 0;
    Node *q = L;
    for (j=1; j<=i; j++){
        if (q->next) q = q->next;
        else break;
    }
    if (j!=i) return ERROR;
    elem = q->e; return OK;
}

// 按元素值索引元素位置
Status LocateNode(NodeList *L, ElemType elem, int i){
    int j = 0;
    Node *q = L;
    while (q->next){
        if (elem == q->e) break;
        j++; q = q->next;
    }
    if (elem == q->e) i = j; return OK;
    return ERROR;
}

// 查询元素的前驱
Status GetPrev(NodeList *L, ElemType elem, ElemType e_prev){
    Node *q = L;
    while (q->next){
        if (q->next->e == elem) break;
        q = q->next;
    }
    if (!q->next) return ERROR;
    e_prev = q; return OK;
}

// 查询元素的后继
Status GetNext(NodeList *L, ElemType elem, ElemType e_next){
    Node *q = L;
    while (q){
        if (q->e == elem) break;
        q = q->next;
    }
    if (!q) return ERROR;
    if (!q->next) return ERROR;
    e_next = q->next; return OK;
}

// 按位置插入节点
Status Insert(NodeList *L, int i, ElemType elem){
    int j = 0;
    Node *q = L;
    for (j=1; j<=i-1; j++) {
        if (q->next) q = q->next;
        else break;
    }
    if (j!=i-1) return ERROR;
    Node *s = (Node *)calloc(1, sizeof(Node));
    s->next = q->next;
    q->next = s;
    s->e = elem;
    return OK;
}

// 按位置删除节点
Status Delete(NodeList *L, int i){
    int j = 0;
    Node *q = L;
    for (j=1; j<=i-1; j++){
        if (q->next) q = q->next;
        else break;
    }
    if (j!=i-1) return ERROR;
    if (!q->next) return ERROR; //Attention!
    Node *s = q->next;
    q->next = s->next;
    free(s); return OK;
}

// * 单链表逆序
Status Reverse(NodeList *L){
    Node *p1, *p2, *p3;
    if ( (!L) || (!L->next) ) return ERROR;
    p1 = L->next;
    p2 = p1->next;
    p1->next = NULL;
    while (p2){             // p1总是指向倒序后单链表的首元节点
        p3 = p2->next;      // p2指向原单链表的首元节点
        p2->next = p1;      // p3缓存下一个节点，下一个节点为NULL时结束
        p1 = p2; p2 = p3;   // 结束时，p1指向倒序后单链表的首元节点
    }
    L->next = p1;
    return OK;
}