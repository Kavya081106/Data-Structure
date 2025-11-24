#include <stdio.h>

#define MAX 1000

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        int A[MAX], stack[MAX];
        int top = -1;
        int expected = 1;
        int i;

        for (i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        i = 0;
        while (i < N) {
          
            stack[++top] = A[i++];

           
            while (top >= 0 && stack[top] == expected) {
                top--;
                expected++;
            }
        }

        
        while (top >= 0 && stack[top] == expected) {
            top--;
            expected++;
        }

        if (expected == N + 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
