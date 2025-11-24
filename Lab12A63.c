#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* save = head;
    while (save->next != NULL)
        save = save->next;

    save->next = newNode;
    return head;
}

void display(struct Node* head) {
    struct Node* save = head;
    while (save != NULL) {
        printf("%d -> ", save->data);
        save = save->next;
    }
    printf("NULL\n");
}


struct Node* copyList(struct Node* originalHead) {
    if (originalHead == NULL)
        return NULL;

    struct Node* newHead = NULL;
    struct Node* pred = NULL;
    struct Node* save = originalHead;

    while (save != NULL) {
        struct Node* newNode = createNode(save->data);

        if (newHead == NULL) {
            newHead = newNode;
            pred = newNode;
        } else {
            pred->next = newNode;
            pred = newNode;
        }

        save = save->next;
    }

    return newHead;
}

int main() {
    struct Node* originalList = NULL;
    struct Node* copiedList = NULL;

    originalList = insertEnd(originalList, 10);
    originalList = insertEnd(originalList, 20);
    originalList = insertEnd(originalList, 30);

    printf("Original List: ");
    display(originalList);

    copiedList = copyList(originalList);

    printf("Copied List:   ");
    display(copiedList);

    return 0;
}
