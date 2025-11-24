#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* first = NULL;   // head pointer

// Insert at end
void insertEnd(int val) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = val;
    newnode->next = NULL;

    if (first == NULL) {
        first = newnode;
    } else {
        struct node* ptr = first;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    printf("%d inserted successfully.\n", val);
}

// Display list
void display() {
    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* ptr = first;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Reverse list
void reverseList() {
    struct node *prev = NULL, *current = first, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first = prev;
    printf("List reversed successfully!\n");
}

// Free all nodes
void freeList() {
    struct node* ptr;
    while (first != NULL) {
        ptr = first;
        first = first->next;
        free(ptr);
    }
}

// Main (menu driven)
int main() {
    int choice, val;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Reverse List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &val);
                insertEnd(val);
                break;

            case 2:
                printf("Linked List: ");
                display();
                break;

            case 3:
                reverseList();
                break;

            case 4:
                freeList();
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
