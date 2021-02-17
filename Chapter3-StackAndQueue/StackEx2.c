#include <stdio.h>
#include <stdlib.h>
#include "SqStackADT.c"

#define BUF_SIZE 50
#define True 1
#define False 0
typedef int Bool;

Bool IsLeftBracket(char a){
    if ( (a=='{') || (a=='[') || (a=='<') || (a=='(') ) return True;
    return False;
}

Bool IsRightBracket(char a){
    if ( (a=='}') || (a==']') || (a=='>') || (a==')') ) return True;
    return False;
}

Bool IsQuote(char a){
    if (a=='"') return True;
    return False;
}

Bool IsPair(char a, char b){
    if ((a=='{')&&(b=='}')) return True;
    if ((a=='[')&&(b==']')) return True;
    if ((a=='<')&&(b=='>')) return True;
    if ((a=='(')&&(b==')')) return True;
    if ((a=='"')&&(b=='"')) return True;
    return False;
}

int main(){
    char input_str[BUF_SIZE] = {"\0"};
    SqStack *p_punc_stack = (SqStack *)malloc(sizeof(SqStack));
    Init(p_punc_stack);
    printf("Please input a string:\n> ");
    fgets(input_str, BUF_SIZE, stdin);
    int i=0, flag=1;
    while (input_str[i]){
        if ( IsLeftBracket(input_str[i]) || IsQuote(input_str[i]) ) Push(p_punc_stack, input_str[i]);
        if ( IsRightBracket(input_str[i]) ){
            char *tmp = (char *)malloc(sizeof(char)); 
            GetTop(p_punc_stack, tmp);
            if (IsPair(*tmp, input_str[i])){
                Pop(p_punc_stack, tmp);
            }
            else {
                printf("Unmatched right bracket %c at %d.\n", input_str[i], i);
                flag = 0;
            }
        }
        i++;
    }
    if (StackLength(p_punc_stack)==0&&flag) printf("Matched!\n");
    else printf("Unmatched left bracket found.\n");
    return 0;
}