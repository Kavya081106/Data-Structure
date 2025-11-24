#include <stdio.h>
#include <stdbool.h>

void quickSort(int lowerBound, int upperBound, int arr[])
{
    bool flag;
    flag = true;
    int i, j, key;

    if (lowerBound < upperBound)
    {
        i = lowerBound;
        j = upperBound + 1;
        key = arr[lowerBound];

        while (flag)
        {
            i = i + 1;

            while (arr[i] < key)
            {
                i = i + 1;
            }

            j = j - 1;

            while (arr[j] > key)
            {
                j = j - 1;
            }

            if (i < j)
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

            else
            {
                flag = false;
            }
        }
        int temp2;
        temp2 = arr[lowerBound];
        arr[lowerBound] = arr[j];
        arr[j] = temp2;

        quickSort(lowerBound, j - 1, arr);
        quickSort(j + 1, upperBound, arr);
    }
}

int main()
{

    int size, lowerBound, upperBound;
    printf("Enter size of array:\n");
    scanf("%d", &size);

    int arr[size];
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(0, size - 1, arr);
    printf("Sorted array is\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}