#include <stdio.h>

void main(){
    int a,b,c;
    printf("Enter number 1 \n");
    scanf("%d",&a);
    printf("Enter number 2 \n");
    scanf("%d",&b);
    printf("Enter number 3 \n");
    scanf("%d",&c);

    int max = (a>b)?((a>c)?a:c):((b>c)?b:c);

    printf("Largest number is %d",max);
}