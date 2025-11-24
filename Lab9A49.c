#include <stdio.h>
#include <stdlib.h>

int main(){

    int *iptr;
    char *cptr;
    float *fptr;

    iptr = (int*)(malloc(sizeof(int)));
    cptr = (char*)(malloc(sizeof(char)));
    fptr = (float*)(malloc(sizeof(float)));

    if(iptr && cptr && fptr){
         *iptr = 9;
         *cptr = 'A';
         *fptr = 15.25;

        printf("%d\n",*iptr);
        printf("%c\n",*cptr);
        printf("%f\n",*fptr);

        free(iptr);
        free(cptr);
        free(fptr);

    }
    else{
        printf("Memory allocation failed!!!");
    }
    return 0;
}