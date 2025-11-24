#include <stdio.h>
#include <string.h>

#define MAX 1000

int isBalanced(char *s) {
    char stack[MAX];
    int top = -1;
    
    for(int i = 0; s[i]; i++) {
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch; 
        } else {
            if(top == -1) return 0; 
            char topChar = stack[top--]; 
            if((ch == ')' && topChar != '(') ||
               (ch == '}' && topChar != '{') ||
               (ch == ']' && topChar != '[')) {
                return 0;
            }
        }
    }
    return top == -1; 
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        char s[MAX];
        scanf("%s", s);
        printf("%d\n", isBalanced(s));
    }
    return 0;
}
