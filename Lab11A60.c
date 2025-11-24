#include <stdio.h>
#include <stdlib.h>

// Node structure for stack
struct node {
    int info;
    struct node* link;
};

// Stack top pointer
struct node* first = NULL;

// Push operation
void push(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    if (newNode == NULL) {  // Memory allocation check
        printf("Memory allocation failed! Cannot push.\n");
        return;
    }

    newNode->info = value;
    newNode->link = first;
    first = newNode;
    printf("%d pushed onto stack.\n", value);
}

// Pop operation
void pop() {
    if (first == NULL) {
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return;
    }

    struct node* temp = first;
    printf("Popped value: %d\n", temp->info);
    first = first->link;
    free(temp);
}

// Peek (top element)
void peek() {
    if (first == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", first->info);
}

// Display stack elements
void display() {
    if (first == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct node* save = first;
    printf("Stack (Top to Bottom): ");
    while (save != NULL) {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

// Free entire stack (cleanup before exit)
void freeStack() {
    while (first != NULL) {
        pop();  // Pop repeatedly until empty
    }
}

int main() {
    int choice, value;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top Element)\n");
        printf("4. Display Stack\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting stack program.\n");
                freeStack();  // cleanup
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
