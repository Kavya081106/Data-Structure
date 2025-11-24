#include <stdio.h>

void main(){
    int power, base, res;
    
    res=1;

    printf("Enter base");
    scanf("%d", &base);
    printf("Enter power");
    scanf("%d", &power);

    for(int i=1; i<=power;i++) {
        res = res*base;
    }

    printf("Power of %d is %d", base, res );

}
