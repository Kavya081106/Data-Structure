#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *prev;
    struct node *next;
};


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}


struct node* deleteAlternate(struct node* head) {
    if (head == NULL)
        return NULL;

    struct node* current = head;
    while (current != NULL && current->next != NULL) {
        struct node* nodeToDelete = current->next;

        
        current->next = nodeToDelete->next;
        if (nodeToDelete->next != NULL)
            nodeToDelete->next->prev = current;

        free(nodeToDelete);
        current = current->next;
    }
    return head;
}

void display(struct node* head) {
    struct node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct node* head = NULL;
    int n, data;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("Original List:\n");
    display(head);

    head = deleteAlternate(head);

    printf("After deleting alternate nodes:\n");
    display(head);

    return 0;
}
