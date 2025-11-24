#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


struct Node* swapKth(struct Node* head, int k) {
    int n = countNodes(head);

    if (k > n) {
        printf("K is greater than number of nodes\n");
        return head;
    }

    if (2 * k - 1 == n) {
        printf("Both Kth nodes are the same (middle), no swap needed\n");
        return head;
    }

    struct Node* prevX = NULL;
    struct Node* currX = head;
    for (int i = 1; i < k; i++) {
        prevX = currX;
        currX = currX->next;
    }

    struct Node* prevY = NULL;
    struct Node* currY = head;
    for (int i = 1; i < n - k + 1; i++) {
        prevY = currY;
        currY = currY->next;
    }

    
    if (prevX != NULL)
        prevX->next = currY;
    else
        head = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        head = currX;

    
    struct Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

    return head;  
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("Original list:\n");
    display(head);

    printf("Enter the value of K: ");
    scanf("%d", &k);

    head = swapKth(head, k);  
    printf("List after swapping %dth node from start and end:\n", k);
    display(head);

    return 0;
}
