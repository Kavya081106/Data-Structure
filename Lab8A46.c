#include <stdio.h>
#define n 100

int queue[n];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == n - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;  // first insertion
    }
    queue[++rear] = x;
    printf("%d inserted into queue.\n", x);
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    int y = queue[front++];
    printf("%d removed from queue.\n", y);

    // Reset queue when last element is deleted
    if (front > rear) {
        front = rear = -1;
    }
    return y;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, data, x;
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting program...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                x = dequeue();
                break;

            case 3:
                display();
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
