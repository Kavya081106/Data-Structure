#include <stdio.h>
#include <math.h>

int main(){
   int originalNum,num,i,j,rem,sum=0;

   for(i=1;i<=1000;i++){
    num=i;
    originalNum = num;
    sum=0;
     while(num>0){
        rem=num%10;
        sum=sum+rem*rem*rem;
        num = num/10;
     }
    

    if(sum==originalNum){
        printf("%d\n", originalNum);
    }
   }

   
    return 0;
}    




//for 3 digit numbers only easy code

// #include <stdio.h>                                                                                           
// #include <math.h>
    

// int main(){                                            
//     int n,rev=0,rem,sum=0,original;
//     printf("Enter number ");    
//     scanf("%d", &n); 

//     original=n;
    
//     while(n!=0){
//         rem = n%10;
//         sum += (int)round(pow(rem, 3));
//         n = n/10;
       

//     }

//     if(sum==original){
//         printf("Number is Amstrong");
//     }else{
//         printf("Number is not Amstrong");
//     }

    
//     return 0;

// }



