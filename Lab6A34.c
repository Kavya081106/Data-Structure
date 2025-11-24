#include <stdio.h>
#define n 100

int stack[n], x, position;
int top = -1;

void push(int x) {
    if (top >= n - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; // special value for error
    }
    return stack[top--];
}

int peep(int position) {
    if (top - position + 1 < 0) {
        printf("Stack Underflow (invalid position)\n");
        return -2; // special value for error
    }
    return stack[top - position + 1];
}

int change(int position, int x) {
    if (top - position + 1 < 0) {
        printf("Stack Underflow (invalid position)\n");
        return -2;
    }
    stack[top - position + 1] = x;
    return stack[top - position + 1];
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, value, pop1;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1 to push\n");
        printf("2 to pop\n");
        printf("3 to peep\n");
        printf("4 to change\n");
        printf("5 to display\n");
        printf("-1 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == -1) {
            printf("Exiting program...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop1 = pop();
                if (pop1 != -1) {
                    printf("Popped element is: %d\n", pop1);
                }
                break;

            case 3:
                printf("Enter position to display: ");
                scanf("%d", &position);
                value = peep(position);
                if (value != -2) {
                    printf("Element at position %d is: %d\n", position, value);
                }
                break;

            case 4:
                printf("Enter position to change: ");
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &x);
                value = change(position, x);
                if (value != -2) {
                    printf("Element at position %d changed to %d\n", position, value);
                }
                break;

            case 5:
                display();
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
