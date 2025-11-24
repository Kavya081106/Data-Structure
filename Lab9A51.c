#include <stdio.h>

int main(){
	
	int n,i;
	printf("Enter size of an array");
	scanf("%d",&n);	
    int arr[n];
	
	printf("Enter array elements whose sum is required");
     int *ptr = arr;
	for(i=0;i<n;i++){
       scanf("%d",(ptr+i));
	}

    int sum=0;
	printf("Sum of numbers is:\n");
	for(i=0;i<n;i++){
        sum+=*(ptr+i);
		

	}
    printf("%d \n",sum);
	return 0;
}
