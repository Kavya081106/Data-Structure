#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* lptr;
    struct node* rptr;
};

struct node* first = NULL;
struct node* last = NULL;

void insertFirst() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter element to insert at front: ");
    scanf("%d", &newNode->info);

    newNode->lptr = NULL;
    newNode->rptr = first;

    if (first != NULL) {
        first->lptr = newNode;
    } else {
        last = newNode;
    }

    first = newNode;
    printf("Node inserted at front.\n");
}

void insertLast() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter element to insert at end: ");
    scanf("%d", &newNode->info);

    newNode->lptr = last;
    newNode->rptr = NULL;

    if (last != NULL) {
        last->rptr = newNode;
    } else {
        first = newNode;
    }

    last = newNode;
    printf("Node inserted at end.\n");
}

void deleteFirst() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* save = first;
    first = first->rptr;

    if (first != NULL) {
        first->lptr = NULL;
    } else {
        last = NULL;
    }

    free(save);
    printf("First node deleted.\n");
}

void deleteLast() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* save = last;
    last = last->lptr;

    if (last != NULL) {
        last->rptr = NULL;
    } else {
        first = NULL;
    }

    free(save);
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

    struct node* save = first;
    int count = 1;

    while (save != NULL && count < position) {
        save = save->rptr;
        count++;
    }

    if (save == NULL) {
        printf("Invalid position. Node not found.\n");
        return;
    }

    if (save == first) {
        deleteFirst();
        return;
    }

    if (save == last) {
        deleteLast();
        return;
    }

    if (save->lptr != NULL) {
        save->lptr->rptr = save->rptr;
    }
    if (save->rptr != NULL) {
        save->rptr->lptr = save->lptr;
    }

    free(save);
    printf("Node at position %d deleted.\n", position);
}

void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* save = first;
    printf("Doubly Linked List: ");
    while (save != NULL) {
        printf("%d <-> ", save->info);
        save = save->rptr;
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
        printf("6. Display all nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                insertFirst();
                break;
            }
            case 2: {
                insertLast();
                break;
            }
            case 3: {
                deleteFirst();
                break;
            }
            case 4: {
                deleteLast();
                break;
            }
            case 5: {
                deleteAtLocation();
                break;
            }
            case 6: {
                display();
                break;
            }
            case 7: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice. Try again.\n");
            }
        }

    } while (choice != 7);

    return 0;
}
