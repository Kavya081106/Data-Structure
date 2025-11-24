#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int stack_precedence(char c){
    if(c=='+' || c=='-') return 2;
    if(c=='*' || c=='/') return 4;
    if(c=='^') return 5;
    if(c=='(') return 0;
    if(c==')') return -1;
    return 8; 
}

int input_precedence(char c){
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 3;
    if(c=='^') return 6;
    if(c=='(') return 9;
    if(c==')') return 0;
    return 7; 
}

int r(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^') return -1;
    return 1; 
}

void revpol(char infix[]){
    int i = 0, j = 0;
    char postfix[100];
    int rank = 0;

    push('(');
    strcat(infix, ")");

    while(i < strlen(infix)){
        char next = infix[i++];
        if(top < 0){
            printf("Invalid Expression.\n");
            return;
        }

        while(stack_precedence(stack[top]) > input_precedence(next)){
            char temp = pop();
            postfix[j++] = temp;
            rank += r(temp);
            if(rank < 1){
                printf("Invalid Rank.\n");
                return;
            }
        }

        if(stack_precedence(stack[top]) != input_precedence(next)){
            push(next);
        } else {
            pop(); 
        }
    }

    if(rank != 1 || top != -1){
        printf("Invalid Expression.\n");
    } else {
        postfix[j] = '\0';
        printf("Postfix: %s\n", postfix);
    }
}

int main(){
    char infix[100];
    printf("Enter an infix string: ");
    scanf("%s", infix);
    revpol(infix);
    return 0;
}
