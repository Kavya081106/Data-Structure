#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    struct node* link;
};

int main() {
    // Create a node dynamically
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    
    printf("Enter data for the node: ");
    scanf("%d", &newNode->info);

   
    newNode->link = NULL;

    
    printf("\nNode created:\n");
    printf("Data: %d\n", newNode->info);
    printf("Link: %p\n", (void*)newNode->link); 

    
    free(newNode);

    return 0;
}
