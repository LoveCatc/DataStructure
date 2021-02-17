#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Status;
typedef int ElemType;
typedef struct SqList{
    ElemType * base_addr;
    int length;
}SqList;

// # Need Fix

// 初始化一个顺序表
Status Init(SqList L){
    L.base_addr = (SqList *)calloc(MAXSIZE, sizeof(ElemType));
    if (!L.base_addr) return OVERFLOW;
    L.length = 0;
    return OK;
}

// 返回表的长度 变形为IsEmpty()
Status Length(SqList L, int l){
    if (!L.base_addr) return ERROR;
    l = L.length;
    return OK;
}

// 按位置索引元素 变形为Prev() Next()
Status GetElem(SqList L, int i, ElemType e){
    if (!L.base_addr) return ERROR;
    if ( (i<1) || (i>L.length) ) return ERROR;
    e = L.base_addr[i-1];
    return OK;
}

// 按元素值定位元素
Status LocateElem(SqList L, ElemType e, int i){
    if (!L.base_addr) return ERROR;
    int j;
    for (j=0; j<L.length; j++) if (L.base_addr[j] == e) break;
    if (j < L.length){
        i = j+1;
        return OK;
    }
    i = -1;
    return ERROR;
}

// 在表指定位置插入元素
Status Insert(SqList L, int i, ElemType e){
    if (!L.base_addr) return ERROR;
    if ( (i<1) || (i>L.length+1) ) return ERROR;
    if (i > MAXSIZE) return ERROR;
    int j;
    for (j=L.length; j>=i; j--) L.base_addr[j] = L.base_addr[j-1];
    L.base_addr[i-1] = e;
    L.length++;
    return OK;
}

// 删除表指定位置的元素
Status Delete(SqList L, int i){
    if (!L.base_addr) return ERROR;
    if ( (i<1) || (i>L.length) ) return ERROR;
    int j;
    for (j=i-1; j<L.length-1; j++) L.base_addr[j] = L.base_addr[j+1];
    L.length--;
    return OK;
}

void QuickSort(SqList L, int left_bound, int right_bound){
    if (left_bound < right_bound){
        int left = left_bound;
        int right = right_bound;
        ElemType mark = L.base_addr[left];
        while (left < right){
            while ( (left < right) && (mark <= L.base_addr[right]) ) right--;
            if ( (left < right) && (mark > L.base_addr[right]) ) L.base_addr[left++] = L.base_addr[right];
            while ( (left < right) && (mark >= L.base_addr[left]) ) left++;
            if ( (left < right) && (mark < L.base_addr[left]) ) L.base_addr[right--] = L.base_addr[left]; 
        }
        QuickSort(L, left_bound, left-1);
        QuickSort(L, left+1, right_bound);
    }
}