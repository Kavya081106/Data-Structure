#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    struct node* link;
};


struct node* first = NULL;


void insertFirst() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter element to insert at front: ");
    scanf("%d", &newNode->info);

    newNode->link = first;
    first = newNode;
}


void insertLast() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter element to insert at end: ");
    scanf("%d", &newNode->info);
    newNode->link = NULL;


    //List is empty
    if (first == NULL) {
        first = newNode;
        return;
    }

    struct node* save = first;
    while (save->link != NULL) {
        save = save->link;
    }
    save->link = newNode;
}


void deleteFirst() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* save = first;
    first = first->link;
    free(save);
    printf("First node deleted.\n");
}


void deleteLast() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (first->link == NULL) {
        free(first);
        first = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct node* save = first;
    struct node* prev = NULL;

    while (save->link != NULL) {
        prev = save;
        save = save->link;
    }

    free(save);
    prev->link = NULL;
    printf("Last node deleted.\n");
}



void deleteAtLocation() {
    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *save = first;
    struct node *pred = NULL;
    int count = 1;

    // Case: Delete first node
    if (position == 1) {
        first = save->link; // Move head to next node
        free(save);         // Free old head
        printf("Node at position 1 deleted.\n");
        return;
    }

    // Traverse to the desired position
    while (save != NULL && count < position) {
        pred = save;
        save = save->link;
        count++;
    }

    // If position is invalid (too large)
    if (save == NULL) {
        printf("Invalid position. Node not found.\n");
        return;
    }

    // Re-link and delete node
    pred->link = save->link;
    free(save);
    printf("Node at position %d deleted.\n", position);
}


void countNodes() {
    struct node* save = first;
    int count = 0;

    while (save != NULL) {
        count++;
        save = save->link;
    }

    printf("Total number of nodes: %d\n", count);
}


void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* save = first;
    printf("Linked List: ");
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}


int main() {
    int choice;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete first node\n");
        printf("4. Delete last node\n");
        printf("5. Delete node at position\n");
        printf("6. Count nodes\n");
        printf("7. Display all nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertFirst(); break;
            case 2: insertLast(); break;
            case 3: deleteFirst(); break;
            case 4: deleteLast(); break;
            case 5: deleteAtLocation(); break;
            case 6: countNodes(); break;
            case 7: display(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 8);

    return 0;
}
