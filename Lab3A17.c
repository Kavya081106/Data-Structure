#include <stdio.h>

int main(){

    int m,n,sum=0;
    printf("Enter number 1");
    scanf("%d",&m);
    printf("Enter number 2");
    scanf("%d",&n);

    for(int i=m; i<=n;i++){
        sum = sum+i;
    }

    printf("Sum of numbers from %d to %d is %d",m,n,sum);


    return 0;
}