#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqStackADT.c"

#define STRLEN 20

int GetRSys(int R){
    char input_str[STRLEN] = "\0";
    printf("Please input a number:\n> ");
    fgets(input_str, STRLEN-1, stdin);
    int input_int = atoi(input_str);
    SqStack *num_stack = (SqStack *)malloc(sizeof(SqStack));    // Watch Out!
    Init(num_stack);
    while (input_int != 0){
        Push(num_stack, input_int%R);
        input_int = (int)(input_int / R);
    }
    while (StackLength(num_stack)){
        int *e =(int *)malloc(sizeof(int)); Pop(num_stack, e);
        printf("%d", *e);
    }
    printf("\n");
    return 0;
}

int main(){
    GetRSys(2);
    return 0;
}