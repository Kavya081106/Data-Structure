#include <stdio.h>

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter number of rows for Matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter number of columns for Matrix 1: ");
    scanf("%d", &cols1);
    printf("Enter number of rows for Matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter number of columns for Matrix 2: ");
    scanf("%d", &cols2);

    // Check for matrix multiplication validity
    if (cols1 != rows2) {
        printf("Invalid matrix dimensions for multiplication.\n");
        return 1;  // Exit the program early
    }

    
    int arr1[rows1][cols1], arr2[rows2][cols2], arr3[rows1][cols2];

    // Input for Matrix 1
    printf("Enter elements of Matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr1[i][j]);
        }
    }

    // Input for Matrix 2
    printf("Enter elements of Matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr2[i][j]);
        }
    }

    // Matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            arr3[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    // Display Result
    printf("Resultant Matrix (Matrix 1 x Matrix 2):\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
