#include<stdio.h>
#include<stdlib.h>

 struct node {
     int data;
     struct node *next;
 };

    struct node * firstLL(int,struct node *);
    struct node * formLL(int,struct node *);
    void reverseALL(struct node *);

 int main(){
    int num,data1;
	struct node *head = NULL;
	struct node *temp1;
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
	temp1 = head;
	printf("linked list before reversing operation is:\n");
	for(int i = 0 ; i < num ; i++){
	    printf("%d ",temp1->data);
	    temp1 = temp1->next;
    }
    printf("\n");
    printf("linked list after the reversing operation is:\n");
    reverseALL(head);
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

void reverseALL(struct node * head){
    struct node *further = head;
    struct node *prev = head;
    further = further->next->next;
    prev = prev -> next;
    head->next = NULL;
    while(prev->next != NULL){
        prev->next = head;
        head = prev;
        prev = further;
        further = further -> next;
    }
    prev->next = head;
    head = prev;
    printf("%d ",head->data);
    while(head->next != NULL){
        head = head->next;
        printf("%d ",head->data);
    }
    return ;
}

