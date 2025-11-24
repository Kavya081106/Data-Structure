#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *lptr,*rptr;
};
struct node *first=NULL;
void Insertatfirst(){
    int data;
    printf("Enter data:");
    scanf("%d",&data);

    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->info=data;
    newNode->lptr=NULL;
    newNode->rptr=first;
    first=newNode;
}
void InsertatEnd(){
    int data;
    printf("Enter data:");
    scanf("%d",&data);  

    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->info=data;
    newNode->rptr=NULL;
    struct node *save=first;

    if(first==NULL){
        first=newNode;
    }

    else{
        while(save->rptr=NULL){
            save=save->rptr;
            newNode->lptr=save;
            save->rptr=newNode;
        }
    }
}

void deleteatloc(){
    struct node *save,*pos;
    save=first;

    if(first==NULL){
        printf("List is Empty");
    }
    else{
        int position;
        printf("Enter position to be deleted:");
        scanf("%d",&position);
        int i=1;
        while(i<position-1){
            save=save->rptr;
            i++;
        }
        pos=save->rptr;
        if(pos->rptr!=NULL){
            pos->rptr->lptr=save;
            save->rptr=pos->rptr;
        }
        free(pos);
    }
}

void display(){
    struct node *save=first;

    while(save!=NULL){
        printf("%d-->",save->info);
        save=save->rptr;
    }
}
int main(){
    int choice;

    while(1){
        printf("Enter 1 for insert at first\n2 for insert at last\n3 for delete at position\n4 to display\n5 to exit:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1 :
            Insertatfirst();
            break;
        case 2:
           InsertatEnd();
           break;
        case 3:
           deleteatloc();
           break;
        case 4:
           display();
           break;
        case 5:
        exit(0);
        default:
            break;
        }
    }
}