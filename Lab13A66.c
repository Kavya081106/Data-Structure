//Write a program to sort elements of a linked list.
#include <stdio.h>
#include <stdlib.h>
	struct node{
		int info;
		struct node *link;
	};
	struct node *first = NULL;
	void sort(){
		
		struct node *temp;
		if(first==NULL){
			printf("Underflow");
		}
		struct node *save = first;
		while(save->link!=NULL){
			save = save->link;
			if(save->info>save->link->info){
				temp = save;
				save = save->link;
				save->link = temp;
			}
			
		}
	}
	void InsertAtEnd() {
	
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
    	printf("Memory allocation denied.\n");
    	return;
	}
//	int val;
//	if(val=-1){
//		break;
//	}
	printf("Enter element to insert at end: ");
	scanf("%d",&newNode->info);
	newNode->link = NULL;
	if(first==NULL){
		first = newNode;
		return;
	}
		struct node* save = first;
		while (save->link != NULL) {
        printf("%d", save->info);
        save = save->link;
    }
    save->link = newNode;
    
}

   void Display() {
   	
    struct node* save = first;
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (save != NULL) {
        printf("%d ->", save->info);
        save = save->link;
    }
    printf("NULL\n");
 }
 
 int main(){
 	InsertAtEnd();
 	sort();
 	Display();
 	return 0;
 }