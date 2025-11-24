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
    } else {
        struct node* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
        return head;
    }
}

int areEqual(struct node* list1, struct node* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->info != list2->info) {
            return 0;
        }
        list1 = list1->link;
        list2 = list2->link;
    }
    return (list1 == NULL && list2 == NULL);
}//Returns 1 (true) only if both lists ended at the same time → completely equal.

int main() {
    struct node *list1 = NULL, *list2 = NULL;
    int n, data;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n);
    printf("Enter %d elements for List 1:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        list1 = insertEnd(list1, data); 
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n);
    printf("Enter %d elements for List 2:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        list2 = insertEnd(list2, data);  
    }

    if (areEqual(list1, list2)) {
        printf("Both linked lists are the same.\n");
    } else {
        printf("The linked lists are NOT the same.\n");
    }

    return 0;
}