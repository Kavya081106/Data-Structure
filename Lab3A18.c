#include <stdio.h>

int main(){

    int n;
    float sum=0.0;
    printf("Enter number till you want average");
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
    float avg = (sum/n);
    printf("Average of given numbers is %f", avg);
    return 0;
}