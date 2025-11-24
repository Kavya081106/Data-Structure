#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* lptr;
    struct node* rptr;
};

struct node *createNode(int val){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->info = val;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}

struct node* insert(struct node* root,int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val < root->info){
        root->lptr = insert(root->lptr,val);
    }
    else if(val > root->info){
        root->rptr = insert(root->rptr,val);
    }
    return root;
}

int search(struct node* root,int val){
    if(root==NULL) return 0;
    if(val < root->info) return search(root->lptr,val);
    else if(val > root->info) return search(root->rptr,val);
    return 1;
}

void inorder(struct node* root){
    if(root==NULL) return;
    inorder(root->lptr);
    printf("%d ", root->info);
    inorder(root->rptr);
}

void preorder(struct node* root){
    if(root==NULL) return;
    printf("%d ", root->info);
    preorder(root->lptr);
    preorder(root->rptr);
}

void postorder(struct node* root){
    if(root==NULL) return;
    postorder(root->lptr);
    postorder(root->rptr);
    printf("%d ", root->info);
}

struct node* findMin(struct node* root) {
    while(root && root->lptr != NULL)
        root = root->lptr;
    return root;
}

struct node* deleteNode(struct node* root, int val) {

    //3 cases possible
    // node has no children
    // node has only one child
    // node has two childs
    // inorder traversal(smallest value in right subtree)
    // Find inorder successor:
    // Go to the right child.
    // Keep going left until you can’t anymore.
    // Copy its value into the current node.
    // Delete that inorder successor from the right subtree (it will be case 1 or 2 now).

    if(root == NULL) return root;

    if(val < root->info) {
        root->lptr = deleteNode(root->lptr, val);
    }
    else if(val > root->info) {
        root->rptr = deleteNode(root->rptr, val);
    }
    else {
        if(root->lptr == NULL) {
            struct node* temp = root->rptr;
            free(root);
            return temp;
        }
        else if(root->rptr == NULL) {
            struct node* temp = root->lptr;
            free(root);
            return temp;
        }
        struct node* temp = findMin(root->rptr);
        root->info = temp->info;
        root->rptr = deleteNode(root->rptr, temp->info);
    }
    return root;
}

int main(){
    struct node* root = NULL;
    int choice, val;

    while(1){
        printf("\n--- Menu ---\n");
        printf("1: Insert\n");
        printf("2: Search\n");
        printf("3: Inorder Traversal\n");
        printf("4: Preorder Traversal\n");
        printf("5: Postorder Traversal\n");
        printf("6: Exit\n");
        printf("7: Delete a value\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root,val);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if(search(root,val))
                    printf("Value found\n");
                else
                    printf("Value not found\n");
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            case 4:
                preorder(root);
                printf("\n");
                break;
            case 5:
                postorder(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                printf("Value deleted if it existed.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
