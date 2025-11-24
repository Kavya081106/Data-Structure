#include <stdio.h>

int main(){
	
	int n;
	printf("Enter size of an array");
	scanf("%d",&n);	
	int arr[n];
	printf("Enter array elements");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Entered array elements are:\n");
	for(int i=0;i<n;i++){
		printf("%d \n",arr[i]);

	}
	return 0;
}
