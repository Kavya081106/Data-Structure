#include <stdio.h>

int main() {
    int arr[100], n = 6, number, i, pos = -1;

    printf("Enter %d sorted array elements in ascending order:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number you want to delete: ");
    scanf("%d", &number);

    // Search for the element
    for(i = 0; i < n; i++) {
        if(arr[i] == number) {
            pos = i;
            break;
        }
    }

    if(pos == -1) {
        printf("Number not found in the array.\n");
    } else {
        // Shift elements to the left to delete
        for(i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;  // Decrease array size

        printf("Array after deletion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
