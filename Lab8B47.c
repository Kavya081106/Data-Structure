#include <stdio.h>
#define SIZE 100

int Q[SIZE];
int F = -1, R = -1;

void enqueue(int value) {
    if ((R + 1) % SIZE == F) {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (F == -1) { // first insertion
        F = 0;
    }
    R = (R + 1) % SIZE;
    Q[R] = value;
    printf("%d enqueued successfully.\n", value);
}

int dequeue() {
    if (F == -1) {
        printf("Circular Queue Underflow\n");
        return -1;
    }

    int Y = Q[F];

    if (F == R) {  // only one element left
        F = R = -1;
    } else {
        F = (F + 1) % SIZE;
    }

    printf("%d dequeued successfully.\n", Y);
    return Y;
}

void display() {
    if (F == -1) {
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    for (int i = F; i != R; i = (i + 1) % SIZE) {
        printf("%d ", Q[i]);
    }
    printf("%d\n", Q[R]);  // print last element
}


int main() {
    int choice, data;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting program...\n");
            break;   // <--- used break instead of exit
        }

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
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
