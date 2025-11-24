#include <stdio.h>

int main() {
    int size, i, j, isDuplicate = 0;

    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter array elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Compare each element with every other element
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate)
            break;
    }

    if (isDuplicate) {
        printf("Duplicate number exists\n");
    } else {
        printf("Duplicate does not exist\n");
    }

    return 0;
}
