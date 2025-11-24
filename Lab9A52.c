#include <stdio.h>




int main() {
    int n, i;

    printf("Enter size of an array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    int *ptr = arr;
    for (i = 0; i < n; i++) {
        scanf("%d", (ptr + i));
    }

   
    int max = *ptr;  

    printf("Maximum number is:\n");
    for (i = 0; i < n; i++) {

        if (*(ptr + i) > max) {
            max = *(ptr + i); 
        }
    }

    
    printf("Max: %d \n", max);

    return 0;
}