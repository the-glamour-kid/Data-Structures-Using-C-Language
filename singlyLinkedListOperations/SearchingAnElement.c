#include<stdio.h>
#include<stdlib.h>

 struct node {
     int data;
     struct node *next;
 };

    struct node * firstLL(int,struct node *);
    struct node * formLL(int,struct node *);
    void elementChecker(struct node *,int);

 int main(){
    int num,data1;
	struct node *head = NULL;
	struct node *temp1;
	struct node *ptr;
	struct node * ptr2;
	int element;
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
	for(int i = 0 ; i < num ; i++){
	    printf("%d ",temp1->data);
	    temp1 = temp1->next;
    }
    printf("\n");
    printf("enter an element to find that is present in the linked list or not: \n");
    scanf("%d",&element);
    elementChecker(head,element);
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
int count = 0;
void elementChecker(struct node * main,int element){
    int index = 0;
    while(main->next != NULL){
        index = index + 1;
        if(element == main->data){
            count++;
            printf("given element is at %d index\n",index);
        }
         main = main->next;
    }
    if(element == main->data){
        index = index + 1;
        count++;
        printf("given element is at %d index\n",index);
    }
    if (count == 0){
        printf("given element is not present in the linked list");
    }
}
