#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->link = NULL;
    return newNode;
}

struct node* insertEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }

    temp->link = newNode;
    return head;
}

void removeDuplicates(struct node* head) {
    struct node* current = head;

    while (current != NULL && current->link != NULL) {
        if (current->info == current->link->info) {
            struct node* temp = current->link;
            current->link = current->link->link;
            free(temp);
        } else {
            current = current->link;
        }
    }
}

void display(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->info);
        head = head->link;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int n, data;

    printf("Enter number of elements in the sorted list: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertEnd(head, data);  
    }

    printf("Original list:\n");
    display(head);

    removeDuplicates(head);

    printf("List after removing duplicates:\n");
    display(head);

    return 0;
}