#include <stdio.h>

int main() {
    int arr[100], n = 6, number, i, j;

    printf("Enter %d sorted array elements in ascending order:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number you want to insert: ");
    scanf("%d", &number);

    // Find the position to insert to maintain sorted order
    for(i = 0; i < n; i++) {
        if(number < arr[i]) {
            break;
        }
    }

    // Shift elements to the right
    for(j = n; j > i; j--) {
        arr[j] = arr[j - 1];
    }

    arr[i] = number;  // Insert the number
    n++;  // Increment array size

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
