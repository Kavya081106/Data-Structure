//SPLIT CIRCULAR
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

struct node* first = NULL;//original
struct node* first1 = NULL;//first half
struct node* first2 = NULL;//second half

void insert(int val) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->info = val;
    if (first == NULL) {
        first = new;
        new->link = first;
        return;
    }
    struct node* save = first;
    while (save->link != first)
        save = save->link;
    save->link = new;
    new->link = first;
}

void print(struct node* start) {
    if (start == NULL) return;
    struct node* save = start;
    do {
        printf("%d ", save->info);
        save = save->link;
    } while (save != start);
    printf("\n");
}

void split() {
    struct node *slow = first, *fast = first;

    while (fast->link != first && fast->link->link != first) {
        slow = slow->link;
        fast = fast->link->link;
    }

    first1 = first;
    first2 = slow->link;

    slow->link = first1;

    struct node* save = first2;
    while (save->link != first)
        save = save->link;
    save->link = first2;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    printf("Original List:\n");
    print(first);

    split();

    printf("First Half:\n");
    print(first1);

    printf("Second Half:\n");
    print(first2);

    return 0;
}