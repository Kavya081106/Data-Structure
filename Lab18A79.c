#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int info;
    struct node* lptr;
    struct node* rptr;
};

// Create new node
struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = val;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

// Utility function to search index of a value in postorder[]
int search(int* arr, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct node* constructTree(int* preorder, int* postorder, int* preIndex, int start, int end, int size) {
    if (*preIndex >= size || start > end)
        return NULL;

    // Create root from preorder
    struct node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    // If there is only one element, return node
    if (start == end || *preIndex >= size)
        return root;

    // Next preorder element is left child
    int postIndex = search(postorder, start, end, preorder[*preIndex]);

    // If found, construct left & right subtrees
    if (postIndex != -1) {
        root->lptr = constructTree(preorder, postorder, preIndex, start, postIndex, size);
        root->rptr = constructTree(preorder, postorder, preIndex, postIndex + 1, end - 1, size);
    }

    return root;
}

// Print Inorder traversal (for checking correctness)
void inorder(struct node* root) {
    if (root == NULL)
        return;
    inorder(root->lptr);
    printf("%d ", root->info);
    inorder(root->rptr);
}

int main() {
    int nodeCount;

    printf("Enter number of nodes: ");
    scanf("%d", &nodeCount);

    int preorder[nodeCount], postorder[nodeCount];

    printf("Enter preorder elements: ");
    for (int i = 0; i < nodeCount; i++)
        scanf("%d", &preorder[i]);

    printf("Enter postorder elements: ");
    for (int i = 0; i < nodeCount; i++)
        scanf("%d", &postorder[i]);

    int preIndex = 0;
    struct node* root = constructTree(preorder, postorder, &preIndex, 0, nodeCount - 1, nodeCount);

    printf("\nInorder traversal of constructed tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
