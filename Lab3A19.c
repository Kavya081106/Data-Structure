#include <stdio.h>

int main(){
    int size, max, min, maxPosition, minPosition;

    printf("Enter size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter elements: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    // Initialize max and min correctly before the loop
    max = arr[0];
    min = arr[0];
    maxPosition = 0;
    minPosition = 0;

    for(int i = 1; i < size; i++){  // Start from index 1
        if(arr[i] > max){
            max = arr[i];
            maxPosition = i;
        }
        if(arr[i] < min){
            min = arr[i];
            minPosition = i;
        }
    }

    printf("Max value is %d and its index is %d\n", max, maxPosition);
    printf("Min value is %d and its index is %d\n", min, minPosition);

    return 0;
}