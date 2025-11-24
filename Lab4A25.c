#include <stdio.h>

int main() {
    int number, location;
    int arr[100];

   
    printf("Enter 6 array elements:\n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("Enter location where you want to delete (1 to 6): ");
    scanf("%d", &location);

   
    int index = location - 1;

   
    for (int i = index; i < 5; i++) {
        arr[i] = arr[i + 1];
    }

   
    printf("Array after deletion:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
