#include <stdio.h>

int linearSearch(int size, int arr[], int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i; // return index
        }
    }
    return -1; // not found
}

int main()
{
    int size, key;
    printf("Enter size of array:\n");
    scanf("%d", &size);

    int arr[size];
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search:\n");
    scanf("%d", &key);

    int index = linearSearch(size, arr, key);

    if (index == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", index);

    return 0;
}
