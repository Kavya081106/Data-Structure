#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;
int index = 0;
char input[MAX];

void push(char value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    stack[top] = value;
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    char value = stack[top];
    top--;
    return value;
}

char nextChar() {
    char ch = input[index];
    index++;
    return ch;
}

void recognize() {
    char next;
    push('c');
    next = nextChar();
    while (next != 'c') {
        if (next == '\0' || next == ' ') {
            printf("INVALID STRING\n");
            return;
        } else {
            push(next);
        }
        next = nextChar();
    }
    while (stack[top] != 'c') {
        next = nextChar();
        char x = pop();
        if (next != x) {
            printf("INVALID STRING\n");
            return;
        }
    }
    next = nextChar();
    if (next == ' ' || next == '\0') {
        printf("VALID STRING\n");
    } else {
        printf("INVALID STRING\n");
    }
    return;
}

int main() {
    printf("Enter the string: ");
    fgets(input, MAX, stdin);
    int len = strlen(input);
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    recognize();
    return 0;
}
