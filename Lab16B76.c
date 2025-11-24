#include <stdio.h>
#include <stdlib.h>

struct node{
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
    int choice;
    if(root==NULL){
        return createNode(val);
    }
    printf("Enter 1 for left subtree and 2 for right subtree insertion:");
    scanf("%d", &choice);
    if(choice==1){
        if(val < root->info){
        root->lptr = insert(root->lptr,val);
        }
    }

    if(choice==2){
         if(val > root->info){
         root->rptr = insert(root->rptr,val);
        }
    }
    return root;
}

int isSame(struct node* root1,struct node* root2){
    if(root1==NULL && root2==NULL){
        return 1;
    }

    if(root1==NULL || root2==NULL){
        return 0;
    }

    return(root1->info==root2->info) && isSame(root1->lptr,root2->lptr) && isSame(root1->rptr,root2->rptr);
}

void main(){
    struct node* root1 = NULL;
    struct node* root2 = NULL;
    int val,nodeCount;

    printf("Enter number of nodes for tree 1:");
    scanf("%d", &nodeCount);

    for(int i=0;i<nodeCount;i++){
        root1 = insert(root1, val);
    }

    printf("Enter number of nodes for tree 2:");
    scanf("%d", &nodeCount);

    for(int i=0;i<nodeCount;i++){
        root2 = insert(root2,val);
    }

    if(isSame(root1,root2)){
        printf("Given two tree are same\n");
    }
    else{
        printf("Given two tree are not same\n");
    }
    
    

    

}