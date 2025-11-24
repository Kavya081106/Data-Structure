#include <stdio.h>

#define MAX 100


struct Interval {
    int start;
    int end;
};


void sortIntervals(struct Interval arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j].start > arr[j+1].start) {
                struct Interval temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void mergeIntervals(struct Interval arr[], int n) {
    sortIntervals(arr, n);

    int i = 0;
    while(i < n) {
        int start = arr[i].start;
        int end = arr[i].end;

       
        while(i < n - 1 && arr[i+1].start <= end) {
            if(arr[i+1].end > end)
                end = arr[i+1].end;
            i++;
        }

       
        printf("{%d, %d} ", start, end);
        i++;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval arr[MAX];

    printf("Enter %d intervals (start end):\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    printf("Merged intervals:\n");
    mergeIntervals(arr, n);

    return 0;
}
