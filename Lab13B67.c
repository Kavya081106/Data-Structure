#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    struct node *link;
};

struct node *first = NULL;


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void insertNode() {
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = val;
    newNode->link = NULL;

    if (first == NULL) {
        first = newNode;
    } else {
        struct node *temp = first;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newNode;
    }
}


void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = first;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}


void insertGCDBetweenNodes() {
    struct node *curr = first;

    while (curr != NULL && curr->link != NULL) {
        int a = curr->info;
        int b = curr->link->info;
        int g = gcd(a, b);

        
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = g;
        newNode->link = curr->link;

        
        curr->link = newNode;

        
        curr = newNode->link;
    }

    printf("GCDs inserted successfully.\n");
}


int main() {
    int choice;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert node\n");
        printf("2. Display list\n");
        printf("3. Insert GCD between adjacent nodes\n");
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
            insertGCDBetweenNodes();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
