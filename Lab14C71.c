#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node *link;
};

// Create a new node
struct node* createNode(int c, int e) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->coeff = c;
    temp->expo = e;
    temp->link = NULL;
    return temp;
}

// Insert term in descending order of exponent
struct node* insert(struct node* head, int c, int e) {
    struct node* temp = createNode(c, e);
    if (head == NULL || head->expo < e) {
        temp->link = head;
        return temp;
    }

    struct node* curr = head;
    while (curr->link != NULL && curr->link->expo >= e)
        curr = curr->link;

    if (curr->expo == e) {
        curr->coeff += c;
    } else {
        temp->link = curr->link;
        curr->link = temp;
    }
    return head;
}

// Add two polynomial linked lists
struct node* addPoly(struct node* p1, struct node* p2) {
    struct node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->expo == p2->expo) {
            result = insert(result, p1->coeff + p2->coeff, p1->expo);
            p1 = p1->link;
            p2 = p2->link;
        } else if (p1->expo > p2->expo) {
            result = insert(result, p1->coeff, p1->expo);
            p1 = p1->link;
        } else {
            result = insert(result, p2->coeff, p2->expo);
            p2 = p2->link;
        }
    }

    // Remaining terms
    while (p1 != NULL) {
        result = insert(result, p1->coeff, p1->expo);
        p1 = p1->link;
    }
    while (p2 != NULL) {
        result = insert(result, p2->coeff, p2->expo);
        p2 = p2->link;
    }

    return result;
}

// Display the polynomial
void display(struct node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->link;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n, coeff, expo;

    // First polynomial input
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and expo: ");
        scanf("%d %d", &coeff, &expo);
        poly1 = insert(poly1, coeff, expo);
    }

    // Second polynomial input
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and expo: ");
        scanf("%d %d", &coeff, &expo);
        poly2 = insert(poly2, coeff, expo);
    }

    // Add polynomials
    sum = addPoly(poly1, poly2);

    printf("\nFirst Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);
    printf("Sum of Polynomials: ");
    display(sum);

    return 0;
}
