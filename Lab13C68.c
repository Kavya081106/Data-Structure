#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    struct node* link;
};

struct node* first = NULL;


void insertNode() {
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = val;
    newNode->link = NULL;

    if (first == NULL) {
        first = newNode;
    } else {
        struct node* temp = first;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newNode;
    }
}


void display() {
    struct node* temp = first;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}


void swapConsecutiveNodes() {
    if (first == NULL || first->link == NULL) {
        printf("List too short to swap.\n");
        return;
    }

    struct node* prev = NULL;
    struct node* curr = first;
    struct node* next = NULL;

    
    first = curr->link;

    while (curr != NULL && curr->link != NULL) {
        next = curr->link;

        
        curr->link = next->link;
        next->link = curr;

        if (prev != NULL) {
            prev->link = next;
        }

       
        prev = curr;
        curr = curr->link;
    }

    printf("Consecutive nodes swapped successfully.\n");
}


int main() {
    int choice;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert node\n");
        printf("2. Display list\n");
        printf("3. Swap consecutive nodes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insertNode();
            break;
        case 2:
            display();
            break;
        case 3:
            swapConsecutiveNodes();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
