#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int *ptr = arr;  

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", (ptr + i));  
    }

   
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(*(ptr + i) > *(ptr + j)) {
                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }

  
    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));  
    }
    printf("\n");

    return 0;
}
