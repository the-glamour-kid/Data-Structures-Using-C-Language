#include<stdio.h>
#include<stdlib.h>

 struct node {
     int data;
     struct node *next;
 };
 
    struct node * firstLL(int,struct node *);
    struct node * formLL(int,struct node *);
    struct node * addAtTheEnd(int ,struct node *);
 
 int main(){
    int num,data1;
    int c;
	struct node *head = NULL;
	struct node *temp1;
	struct node *ptr;
	struct node * ptr2;
	head = (struct node *) malloc(sizeof(struct node));
	temp1 = head;
	
	printf("enter number of values:\n");
	scanf("%d", &num); 

	if (num == 1){
	    printf("enter the single element:\n");
		scanf("%d",&data1);
		head->data = data1;
		head->next = NULL;
		printf("%d",head->data);
	}

	else{
	for(int i = 0 ; i < num ; i++){

		if (i == 0){
			printf("enter %d value:",i+1);
			scanf("%d",&data1);
			temp1 = firstLL(data1,temp1);
		}
		else{
			printf("enter %d value:",i+1);
			scanf("%d",&data1);
			temp1 = formLL(data1,temp1);
		    }
	    }
	}
	ptr = head;
	for(int i = 0 ; i < num ; i++){
	    printf("%d ",ptr->data);
	    ptr = ptr->next;
    }
    printf("\n");
    printf("enter 1 to add a node at the end of the linked list\n");
    
    label:
    scanf("%d",&c);
    if (c == 1){
        printf("enter the value:");
        scanf("%d",&data1);
        temp1 = addAtTheEnd(data1,temp1);
        printf("%d is added at the end of  the  linked list\n",data1);
        goto label;
        printf("enter 1 to add a node at the end of the linked list:");
        }
    else if(c != 1){
        ptr = head;
        printf("linked list after adding nodes at the end\n");
        while(ptr->next != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf(" %d",ptr->data);
    }
}
 
struct node * firstLL(int LLData,struct node *temp1){
	temp1->data = LLData;
	temp1->next = NULL;
	return temp1;
}

struct node * formLL(int LLData,struct node *temp1){
    struct node *temp2 = NULL;
	temp2 = (struct node *) malloc(sizeof(struct node));
	temp2->data = LLData;
	temp2->next = NULL;
	temp1->next = temp2;
	temp1 = temp2;
	return temp1;
}

struct node * addAtTheEnd(int data,struct node *temp1){
    struct node *temp2 = (struct node *) malloc(sizeof(struct node));
    temp2->data = data;
    temp2->next = NULL;
    temp1->next = temp2;
    return temp2;
}
 
 