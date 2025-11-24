#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find smallest element (go left till NULL)
struct node* findMin(struct node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Find largest element (go right till NULL)
struct node* findMax(struct node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

// Inorder traversal (for checking)
void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements to insert into BST:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal of BST: ");
    inorder(root);

    struct node* minNode = findMin(root);
    struct node* maxNode = findMax(root);

    if (minNode)
        printf("\nSmallest element = %d", minNode->data);
    if (maxNode)
        printf("\nLargest element = %d", maxNode->data);

    printf("\n");
    return 0;
}
