#include <stdio.h>

int main(){
	
	int n,i;
	printf("Enter size of an array");
	scanf("%d",&n);	
    int arr[n];
	
	printf("Enter array elements");
     int *ptr = arr;
	for(i=0;i<n;i++){
       scanf("%d",(ptr+i));
	}
	printf("Entered array elements are:\n");
	for(i=0;i<n;i++){
		printf("%d \n",*(ptr+i));

	}
	return 0;
}
