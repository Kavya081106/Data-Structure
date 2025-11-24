#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* lptr;
    struct node* rptr;
};

int main() {
    // Create root
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->info = 4;
    root->lptr = NULL;
    root->rptr = NULL;

    // Left child of root
    root->lptr = (struct node*)malloc(sizeof(struct node));
    root->lptr->info = 1;
    root->lptr->lptr = NULL;
    root->lptr->rptr = NULL;

    // Right child of root
    root->rptr = (struct node*)malloc(sizeof(struct node));
    root->rptr->info = 6;
    root->rptr->lptr = NULL;
    root->rptr->rptr = NULL;

    // Left child of node 1
    root->lptr->lptr = (struct node*)malloc(sizeof(struct node));
    root->lptr->lptr->info = 0;
    root->lptr->lptr->lptr = NULL;
    root->lptr->lptr->rptr = NULL;

    // Print structure
    printf("Root: %d\n", root->info);
    printf("Left Child: %d\n", root->lptr->info);
    printf("Right Child: %d\n", root->rptr->info);
    printf("Left->Left Child: %d\n", root->lptr->lptr->info);

    // Free memory
    free(root->lptr->lptr);
    free(root->lptr);
    free(root->rptr);
    free(root);

    return 0;
}
