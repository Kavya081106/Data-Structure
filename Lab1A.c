#include <stdio.h>
#define PI 3.14

void main(){
    int radius;
    float area;

    printf("Enter radius of circle");
    scanf("%d",&radius);
    area = PI*radius*radius;
    printf("Area of circle is of radius %d:%f",radius,area);
}