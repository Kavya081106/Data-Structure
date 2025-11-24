#include <stdio.h>

void bubbleSort(int arr[], int size){
    int last = size-1;

    for(int i=0;i<size-1;i++){
        int exchanges=0;
        for(int j=0;j<last;j++){
            if(arr[j]>arr[j+1]){
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                exchanges = exchanges+1;
            }
        }

        if(exchanges==0){
            printf("Vector is sorted");
            break;
        }
        else{
            last = last-1;
        }
    }
}


int main()
{

    int size;
    printf("Enter size of array:\n");
    scanf("%d", &size);

    int arr[size];
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, size);
    printf("Sorted array is\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}