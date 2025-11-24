#include <stdio.h>

int main(){
    int size1,size2;

    // Write a program to delete a number from a given location in an array. [1,2,3,4,5]

    printf("Enter size of array 1:");
    scanf("%d", &size1);
    printf("Enter size of array 2:");
    scanf("%d", &size2);

    int arr1[size1];
    int arr2[size2];

    printf("Enter array 1 elements:");
    for(int i=0;i<size1;i++){
        scanf("%d", &arr1[i]);
    }

    printf("Enter array 2 elements:");
    for(int i=0;i<size2;i++){
        scanf("%d", &arr2[i]);
    }

    int size3 = size1+size2;

    int arr3[size3];


    for(int i = 0; i < size1; i++) {
        arr3[i] = arr1[i];
    }
    for(int i = 0; i < size2; i++) {
        arr3[size1 + i] = arr2[i];
    }

    // Print merged array
    printf("Array 3 elements are:\n");
    for(int i = 0; i < size3; i++) {
        printf("%d ", arr3[i]);
    }






    return 0;
}