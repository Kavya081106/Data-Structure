#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *last = NULL;



struct node *insertAtfirst(struct node *first){
    int x;
    printf("Enter x: ");
    scanf("%d", &x);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    
    newNode->info=x;

    if(first==NULL){
        newNode->link = newNode;
        first=last=newNode;
        return first;
    }

    newNode->link = first;
    first = newNode;
    last->link = first;
    return first;
}

struct node *insertAtEnd(struct node *first){
    int x;
    printf("Enter x: ");
    scanf("%d", &x);

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info=x;
    if(first==NULL){
        newNode->link = newNode;
        first=last=newNode;
        return first;
    }
    struct node *save=first;
    while(save->link!=first){
        save=save->link;
    }
    newNode->link = first;
    save->link = newNode;
    last = newNode;

    return first;
    

}

struct node *deleteAtLoc(struct node *first) {
    int loc;
    printf("Enter location where you want to delete: ");
    scanf("%d", &loc);

    if (first == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct node *temp = first, *prev = last;

  //Check if the value is in the first node
    if (first->info == loc) {
        //Only one node in the list
        if (first == first->link) {
            free(first);
            last = NULL;
            return NULL;
        }
        prev->link = first->link;
        first = first->link;
        free(temp);
        return first;
    }

   
    do {
        prev = temp;
        temp = temp->link;
        if (temp->info == loc) {
            prev->link = temp->link;
            if (temp == last)
                last = prev;
            free(temp);
            return first;
        }
    } while (temp != first);

    printf("Value not found.\n");
    return first;
}


void display(struct node *first) {
    struct node *temp = first;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d -> ", temp->info);
        temp = temp->link;
    } while (temp != first);
    printf("NULL\n");
    
}


int main(){
    struct node *first=NULL;
    int choice;
   

   do {
        printf("\n====== MENU ======\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete node at position\n");
        printf("4. Display all nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            
            case 1: first=insertAtfirst(first);break;
            
            case 2:first=insertAtEnd(first);break;

            case 3: deleteAtLoc(first); break;
            case 4: display(first); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);
    return 0;
}