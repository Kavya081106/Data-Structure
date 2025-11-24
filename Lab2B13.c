#include <stdio.h>

int main() {
    int a, b, i, j, isPrime;

    printf("Enter number 1: ");
    scanf("%d", &a);
    printf("Enter number 2: ");
    scanf("%d", &b);

    printf("Prime numbers between %d and %d:\n", a, b);

    for (i = a; i <= b; i++) {
        if (i < 2)
            continue;
        isPrime = 1;  // Assume i is prime
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = 0;  // Not prime
                break;
            }
        }
        if (isPrime==1)
            printf("%d ", i);
    }

    return 0;
}

