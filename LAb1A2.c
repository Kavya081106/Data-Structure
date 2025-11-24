#include <stdio.h>

void main(){
    int num;
    printf("Enter number");
    scanf("%d",&num);
    if(num%2==0){
        printf("Given number is even");
    }else{
        printf("Given number is odd");
    }
}