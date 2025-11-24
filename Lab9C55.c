#include <stdio.h>
#include <string.h>


struct Student {
    int roll_no;
    char name[50];
    char branch[30];
    int batch_no;
};

int main() {
    struct Student s1;
    struct Student *ptr;

    ptr = &s1;

    printf("Enter Roll Number: ");
    scanf("%d", &ptr->roll_no);

    printf("Enter Name: ");
    scanf("%s", ptr->name); 

    printf("Enter Branch: ");
    scanf("%s", ptr->branch);

    printf("Enter Batch Number: ");
    scanf("%d", &ptr->batch_no);

    printf("\nStudent Details:\n");
    printf("Roll No: %d\n", ptr->roll_no);
    printf("Name: %s\n", ptr->name);
    printf("Branch: %s\n", ptr->branch);
    printf("Batch No: %d\n", ptr->batch_no);

    return 0;
}
