// Write a menu driven program to implement following operations on the 
// Doubled Ended Queue using an Array 
// • Insert at front end, Insert at rear end 
// • Delete from front end, Delete from rear end 
// • Display all elements of the queue 


#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int Q[SIZE];
int F=-1;
int R=-1;

void insert_at_front(int value){
    if(F==0){
        printf("Queue Overflow(front)");
        return;
    }
    if(F==-1){
        F=R=0;
    }
    else{
        F--;
    }
    Q[F]=value;
    printf("%d inserted at front sucessfully",Q[F]);
}
void insert_at_rear(int value){
    if(R>=SIZE){
        printf("Queue Overflow");
        return;
    }
    R++;
    Q[R]=value;
    if(F==-1){
        F=0;
    }
}

int delete_at_front(){
   if(F==-1){
        printf("Queue Underflow");
        return -1;
    }
    int Y;
    Y=Q[F];
    if(F==R){
        F=-1;
        R=-1;
    }
    else{
       F++;
    }
    printf(" %d Deleted successfully",Y);
    return(Y);
}
int delete_at_rear(){
    if(R==-1){
        printf("Underflow");
        return 0;
    }
    int Y=Q[R];
    if(R==F){
        F=-1;
        R=-1;
    }
    else{
        R--;
    }
    printf("%d Deleted Sucessfully",Y);
    return(Y);
}
void display(){
    int i=F;
    while(1){
        printf("%d-->",Q[i]);
        if(i==R){
            break;
        }
        i=(i+1)%SIZE;
    }
}
void main(){
    int choice,data;
    while(1){
        printf("Enter 1 to insert at front : \n");
        printf("Enter 2 to insert at rear : \n");
        printf("Enter 3 to delete from front : \n");
        printf("Enter 4 to delete from rear : \n");
        printf("Enter 5 to display :\n");
        printf("Enter 6 to exit : ");

        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter data : ");
            scanf("%d",&data);
            insert_at_front(data);
            break;

            case 2:
            printf("Enter data : ");
            scanf("%d",&data);
            insert_at_rear(data);
            break;

            case 3:
            delete_at_front();
            break;

            case 4:
            delete_at_rear();
            break;

            case 5:
            display();
            break;
        
            case 6:
            exit(0);
        }
    }
}