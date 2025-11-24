#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char expr[]) {
    int i = 0, op1, op2;
    char ch;
    while ((ch = expr[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < op2; j++) res *= op1;
                    push(res);
                    break;
                }
            }
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression (single digits): ");
    scanf("%s", postfix);
    printf("Result = %d\n", evaluatePostfix(postfix));
    return 0;
}
