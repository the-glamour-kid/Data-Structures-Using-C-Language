#include<stdio.h>
#include<stdlib.h>

 struct node {
     int data;
     struct node *next;
 };

    struct node * firstLL(int,struct node *);
    struct node * formLL(int,struct node *);
    int deleteLast(struct node *,int);

 int main(){
    int num,data1;
    int c,count;
    //head pointer
	struct node *head = NULL;
	//node creating pointer
	struct node *temp1;
	//printing sequence pointer
	struct node *ptr;
	//pointer to point last node
	struct node *last;
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
	printf("linked list is: ");
	for(int i = 0 ; i < num ; i++){
	    printf("%d ",ptr->data);
	    ptr = ptr->next;
    }
    last = ptr;
    count = num;
    printf("\n");
    label:
    printf("enter 1 number to delete the last node from linked list: \n");
    scanf("%d",&c);
    if ((c == 1) && (num != 0)){
        num = deleteLast(head,num);
        if (num > 0){
        goto label;
        }
    }
    else if (c != 1 && num != 0){
        struct node *temp3 = head;
        printf("resultant linked list is: ");
        while(temp3->next != NULL){
            printf("%d ",temp3->data);
            temp3 = temp3->next;
        }
        printf("%d",temp3->data);
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

int deleteLast(struct node *delPtr,int num){
    if (num > 1){
    for(int i = 0 ; i < num-2 ; i ++){
        delPtr = delPtr->next;
    }
    struct node *temp2 = delPtr;
    temp2 = temp2->next;
    delPtr->next = NULL;
    printf("%d is deleted\n",temp2->data);
    free(temp2);
    num = num - 1;
    }
    else{
        printf("linked list is empty\n");
        num = num - 1;
    }
    return num;
}

