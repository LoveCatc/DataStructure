#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType; 
typedef struct Node{
    ElemType value;
    struct Node *next;
}Node, NodeList;

void QuickSortNodeList(Node *head_node, Node *end_node){    // 从首元节点开始，尾节点后继结束
    if (head_node == NULL) return;
    if (head_node == end_node) return;
    Node *pslow = head_node;     
    Node *pfast = pslow->next;
    Node *ps_prev = pslow;
    while (pfast != end_node){
        if (head_node->value > pfast->value){
            ps_prev = pslow;
            pslow = pslow->next;
            int tmp = pfast->value;
            pfast->value = pslow->value;
            pslow->value = tmp;
        }
        pfast = pfast->next;
    }
    int tmp = pslow->value;
    pslow->value = head_node->value;
    head_node->value = tmp;
    QuickSortNodeList(head_node, pslow);
    QuickSortNodeList(pslow->next, NULL);
}

int main(){
    int test[6] = {1, 3, 2, 4, 6, 5};
    int i = 0; 
    Node *H = (Node *)calloc(1, sizeof(Node));
    H->next = (Node *)calloc(1, sizeof(Node));
    Node *p = H->next;
    for (i=0; i<=5; i++){
        p->value = test[i];
        p->next = (Node *)calloc(1, sizeof(Node));
        if (i!=5) p = p->next; 
    }
    p->next = NULL;
    QuickSortNodeList(H, p);
    p = H->next;
    for (i=0; i<=5; i++){
        printf("%d ", p->value);
        p = p->next;
    }
    return 0;
}