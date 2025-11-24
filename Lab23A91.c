#include <stdio.h>

void insertionSort(int arr[],int size){
    int i=1,j,key;

    while(i<size){
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j = j-1;
        }

        arr[j+1]=key;
        i=i+1;
    }
}

int main(){
    int size;
    printf("Enter size of array:\n");
    scanf("%d", &size);

    int arr[size];
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }


    insertionSort(arr, size);
    printf("Sorted array is\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}