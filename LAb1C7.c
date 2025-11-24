#include <stdio.h>

void main(){
    int days,weeks,years;
    days=0;
    weeks=0;
    years=0;
    printf("Enter days \n");
    scanf("%d",&days);
     while (days >= 7) {
        if (days >= 365) {
            days = days-365;
            years++;
        } else if (days >= 7) {
            days = days-7;
            weeks++;
        }
    }

    printf("%d:%d:%d\n", years,weeks,days);
}
