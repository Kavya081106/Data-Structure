#include <stdio.h>

int main(){
    int rows,cols,i,j;
    printf("Enter number of rows:");
    scanf("%d",&rows);
    printf("Enter number of columns:");
    scanf("%d",&cols);
    int arr1[rows][cols], arr2[rows][cols], arr3[rows][cols];
    printf("Enter matrix 1:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("Enter element [%d][%d]",(i+1),(j+1) );
            scanf("%d",& arr1[i][j]);
        }
        printf("\n");
    }

    printf("First matrix is \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d", arr1[i][j]);
        }
        printf("\n");
    }

    printf("Enter matrix 2:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("Enter element [%d][%d]",(i+1),(j+1) );
            scanf("%d",& arr2[i][j]);
        }
        printf("\n");
    }

    printf("Second matrix is \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d", arr2[i][j]);
        }
        printf("\n");
    }


    printf("Third matrix is \n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            arr3[i][j] = arr1[i][j]+arr2[i][j];
            printf("%d",arr3[i][j]);
        }
        printf("\n");
    }


    return 0;
}