//88. Write a program to implement a Binary Search using Array. (Iterative & recursive) 

#include <stdio.h>

int BinarySearchIterative(int arr[], int key, int size){
    int left = 0;
    int right = size-1;
    

    while(left<=right){
        int middle = (left+right)/2;
        if(arr[middle]==key){
            return middle;
        }
        else if(key<arr[middle]){
            right=middle-1;
        }
        else{
            left = middle+1;
        }
    }

    return -1;
}



int main(){
    
    int size, key;
    printf("Enter size of array:\n");
    scanf("%d", &size);

    int arr[size];
    printf("Enter array elements(Sorted): ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search:\n");
    scanf("%d", &key);

    printf("Index is %d", BinarySearchIterative(arr,key,size));

    return 0;
}