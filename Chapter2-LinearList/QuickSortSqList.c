#include <stdio.h>

void QuickSortSqList(int *sqlist, int left_bound, int right_bound){
    if (left_bound < right_bound){  // as recursion condition
        int left = left_bound;
        int right = right_bound;
        int mark = sqlist[left];    // benchmark
        while (left < right){
            while ((sqlist[right] >= mark) && (left < right)) right--;
            if (left < right) sqlist[left++] = sqlist[right];
            while ((sqlist[left] <= mark)  && (left < right)) left++;
            if (left < right) sqlist[right--] = sqlist[left];
        }
        sqlist[left] = mark;
        QuickSortSqList(sqlist, left_bound, left-1);
        QuickSortSqList(sqlist, left+1, right_bound);
    }
}

int main(){
    int i = 0;
    int testlist[10] = {1, 3, 4, 2, 5, 7, 9, 8, 0, 6};
    printf("Before: \n");
    for (i=0; i<10; i++) printf("%d ", testlist[i]);
    printf("\n");
    QuickSortSqList(testlist, 0, 9);
    printf("After: \n");
    for (i=0; i<10; i++) printf("%d ", testlist[i]);
    printf("\n");
    return 0;
}