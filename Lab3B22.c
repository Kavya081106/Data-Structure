#include <stdio.h>

int main() {
    int rows, coef = 1, space, i, j;

    // Take input from the user
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    for (i = 0; i < rows; i++) {
        // Print spaces for formatting
        for (space = 1; space <= rows - i; space++)
            printf("  ");

        for (j = 0; j <= i; j++) {
            // First element in each row is always 1
            if (j == 0 || i == 0)
                coef = 1;
            else
                // Calculate value based on previous value
                coef = coef * (i - j + 1) / j;

            printf("%4d", coef);
        }
        printf("\n");
    }

    return 0;
}
