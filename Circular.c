#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};


struct node *last = NULL;
struct node *Insertatfirst(struct node *first){
     int data;
     printf("Enter data:");
    scanf("%d",&data);
    struct node *newNode=(struct node *)malloc(sizeof(struct node));

    newNode->info=data;
    if(first==NULL){
        newNode->link = newNode;
        first = last = newNode;
    }
    else{
       struct node *save=first;
       while(save->link!=first){
          save=save->link;
       }

       save->link=newNode;
       newNode->link=first;
       first=newNode;
    }
     return first;
}
struct node *Insertatend(struct node *first){
    int data;
    printf("Enter data:");
    scanf("%d",&data);

    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    newNode->info=data;

    if(first==NULL){
      newNode->link = newNode;
      first = last = newNode;
    }
    else{
     struct node *save=first;
     while(save->link=first){
        save=save->link;
     }

     save->link=newNode;
     newNode->link=first;
     last=newNode;
}
 return first;
 }


struct node *deleteatloc(struct node *first){
    int data;
    printf("Enter data to delete:");
    scanf("%d",&data);

    if(first==NULL){
        printf("Empty list");
        return NULL;
    }
    struct node *save=first;
    struct node *pred=NULL;

    while(save->info!=data && save!=last){
        pred=save;
        save=save->link;
    }
    if(save->info!=data){
        printf("Element To Delete is not in List\n");
        return first;
    }
    if(save==first){
        struct node *temp=first;
        first=first->link;
        last->link=first;
        printf("Deleted:%d",temp->info);
        free(temp);
        return first;
    }
    if(save==last){
         struct node *temp=last;
         last=pred;
         last->link=first;
         printf("Last node deleted:%d",temp->info);
         free(temp);
         return first;
    }

    if(save!=first && save!=last){
         printf("Element To delete: %d\n",save->info);
         pred->link=save->link;
         free(save);
         return first;
    }

    return first;
}

void display(struct node *first){
       if (first == NULL) {
        printf("Empty\n");
        return;
    }

    struct node *save=first;
    do{
        printf("%d-->",save->info);
        save=save->link;
    }while(save!=first);
}
int main(){
    struct node *first=NULL;
    int choice;
    while(1){
        printf("Enter 1 to insert at first\n2 to insert at end\n3to delete from specified position\n4 to display nodes\n5 to exit");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            first=Insertatfirst(first);
            break;
        case 2:
           first=Insertatend(first);
           break;

        case 3:
          first=deleteatloc(first);
          break;

        case 4:
           display(first);
           break;
        case 5:
        exit(0);

        default:
            break;
        }
    }
}