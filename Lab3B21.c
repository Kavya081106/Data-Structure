#include <stdio.h>

int main() {
    int size, a, b;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to be replaced: ");
    scanf("%d", &a);
    printf("Enter number to replace with: ");
    scanf("%d", &b);

    printf("Replacements done at indices:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] == a) {
            arr[i] = b;
            printf("%d\n", i); // print index
        }
    }

    // Print final array
    printf("Final array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
