#include <stdio.h>

// USING RECURSION

int fact(int num){
    if(num<=1){
        return 1;
    }

    return num* fact(num-1);

}

int main(){
    // USING LOOPS
    int num,res=1;
    printf("Enter number");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    for(int i=num;i>=1;i--){
        res=res*i;
    }
    printf("Factorial of given number is  %d \n", res);

    printf("Recursion Factorial of given number is %d", fact(num));
    
    return 0;
}
