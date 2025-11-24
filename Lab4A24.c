#include <stdio.h>

// Write a program to insert a number at a given location in an array.

int main() {
    int size, n, position;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[100]; 
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to insert: ");
    scanf("%d", &n);
    printf("Enter position (0 to %d): ", size);
    scanf("%d", &position);

    if (position < 0 || position > size) {
        printf("Invalid position!\n");
        return 1;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = n; 
    size++; 

    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


// Write a program to insert a number at a given location in an array. 
//Manual implementation
// #include <stdio.h>

// int main(){
//     int arr[6],x,location,temp;

//     //1 2 3 4 5
//     //1 2 6 3 4 5


//     printf("Enter array elements:\n");
//     for(int i=0;i<5;i++){
//         scanf("%d", &arr[i]);
//     }
//     printf("Entered array elements are:\n");
//     for(int i=0;i<5;i++){
//        printf("%d", arr[i]);
//     }
    
//     printf("Enter element to insert:\n");
//     scanf("%d", &x);

//     printf("Enter location:\n");
//     scanf("%d", &location);


//     for(int i=6;i>=location;i--){
//         arr[i]=arr[i-1];
//     }
    
//     arr[location-1]=x;
    
    
    

//    printf("After inserting element:");

//     for(int i=0;i<6;i++){
//         printf("%d", arr[i]);
//     }

//     return 0;
// }

