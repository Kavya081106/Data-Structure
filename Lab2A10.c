#include <stdio.h>

void main(){
    int num, rev=0;
    printf("Enter number\n");
    scanf("%d", &num);

    while(num>0){

        int rem = num %10;
        rev = (rev*10)+rem;
        num = num/10;
    }

    printf("Reverse number is %d", rev);

}

// #include <stdio.h>

// int main() {
//     int n, rem, rev = 0;
//     int isNegative = 0;

//     printf("Enter a number: ");
//     scanf("%d", &n);

//     // Check if number is negative
//     if(n < 0) {
//         isNegative = 1;
//         n = -n;   // Work with positive part
//     }

//     while(n != 0) {
//         rem = n % 10;          // Extract last digit
//         rev = rev * 10 + rem;  // Build reversed number
//         n = n / 10;            // Remove last digit
//     }

//     if(isNegative) {
//         rev = -rev;   // Add sign back if originally negative
//     }

//     printf("Reversed number is %d", rev);

//     return 0;
// }
