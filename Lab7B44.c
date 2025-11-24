#include <stdio.h>
#include <string.h>
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

int evaluatePrefix(char expr[]) {
    int len = strlen(expr);
    int i, op1, op2;
    char ch;

    for (i = len - 1; i >= 0; i--) {
        ch = expr[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            op1 = pop();
            op2 = pop();
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
    char prefix[MAX];
    printf("Enter prefix expression (single digits): ");
    scanf("%s", prefix);
    printf("Result = %d\n", evaluatePrefix(prefix));
    return 0;
}
