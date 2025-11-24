#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->info = value;
    newNode->link = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->link = newNode;
        rear = newNode;
    }

    printf("%d enqueued into queue.\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Cannot dequeue from empty queue.\n");
        return;
    }

    struct node* save = front;
    printf("Dequeued value: %d\n", save->info);
    front = front->link;

    if (front == NULL) {
        rear = NULL; // Queue is now empty
    }

    free(save);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct node* save = front;
    printf("Queue elements: ");
    while (save != NULL) {
        printf("%d ", save->info);
        save = save->link;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}
