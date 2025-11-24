#include <stdio.h>

int BinarySearchRecursive(int left, int right, int arr[], int key)
{

    if (left <= right)
    {
        int middle = (left + right) / 2;
       if (arr[middle] == key)

        {
            return middle;
        }

        else if (key < arr[middle])
        {
             return BinarySearchRecursive(left, middle - 1, arr, key);
        }
        else
        {
             return BinarySearchRecursive(middle + 1, right, arr, key);
        }
    }

    return -1;
}

int main()
{

    int size, key;
    printf("Enter size of array:\n");
    scanf("%d", &size);

    int arr[size];
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search:\n");
    scanf("%d", &key);

    int left = 0, right = size - 1;

    printf("Index is %d", BinarySearchRecursive(left, right, arr, key));

    return 0;
}