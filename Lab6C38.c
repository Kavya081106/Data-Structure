#include <stdio.h>
#include <string.h>

#define MAX 1000

void removeStars(char *s) {
    char stack[MAX];
    int top = -1;

    for(int i = 0; s[i]; i++) {
        if(s[i] != '*') {
            stack[++top] = s[i]; 
        } else {
            if(top >= 0) top--; 
        }
    }

    
    for(int i = 0; i <= top; i++) {
        putchar(stack[i]);
    }
    printf("\n");
}

int main() {
    char s[MAX];
    scanf("%s", s);
    removeStars(s);
    return 0;
}
