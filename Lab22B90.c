#include <stdio.h>

void selectionSort(int arr[], int size)
{
    for (int i = 0; i <= size - 2; i++)
    {
        int min_index = i;

        for (int j = i + 1; j <= size - 1; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
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

    selectionSort(arr, size);
    printf("Sorted array is\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}