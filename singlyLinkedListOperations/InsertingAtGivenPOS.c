#include<stdio.h>
#include<stdlib.h>

 struct node {
     int data;
     struct node *next;
 };
 
    struct node * firstLL(int,struct node *);
    struct node * formLL(int,struct node *);
    struct node * addAtTheFront(int ,struct node *);
    struct node * addAtTheEnd(int,struct node *);
    struct node * addAtPOS(int,int,struct node *);
 
 int main(){
    int num,data1;
    int c,count,min,max,pos;
    //head pointer
	struct node *head = NULL;
	//node creating pointer
	struct node *temp1;
	//printing sequence pointer 
	struct node *ptr;
	head = (struct node *) malloc(sizeof(struct node));
	temp1 = head;
	
	printf("enter number of values:\n");
	scanf("%d", &num); 
    count = num;
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
    label:
    printf("enter 1 to add a node at the particular position of the linked list\n");
    scanf("%d",&c);
    if (c == 1){
        printf("enter the position values in  between 1 and %d: \n",count+1);
        printf("In which position do you want to enter the value: ");
        scanf("%d",&pos);
        if(pos > 0 && pos <= count+1){
            if(pos == 1){
                printf("enter the value: ");
                scanf("%d",&data1);
                head = addAtTheFront(data1,head);
                printf("%d is added at the beginning of  the  linked list\n",data1);
                count = count + 1;
            }
            else if( pos == count+1 ){
                printf("enter the value: ");
                scanf("%d",&data1);
                temp1 = addAtTheEnd(data1,temp1);
                count = count + 1;
                printf("%d is added at the end of the linked list\n",data1);
            }
            else if(pos > 1 && pos < count){
                printf("enter the value: ");
                scanf("%d",&data1);
                addAtPOS(data1,pos,head);
                count = count + 1;
            }
            goto label;
        }
        else{
            printf("enter the correct position to enter\n");
            goto label;
        }
    }
    else if(c != 1){
        ptr = head;
        printf("resultant linked list after entering all the data\n");
        while(ptr->next != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("%d",ptr->data);
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

struct node * addAtTheFront(int data,struct node *temp1){
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = data;
    new->next = temp1;
    temp1 = new;
    return temp1;
}


struct node * addAtTheEnd(int data,struct node *temp1){
    struct node *temp2 = (struct node *) malloc(sizeof(struct node));
    temp2->data = data;
    temp2->next = NULL;
    temp1->next = temp2;
    return temp2;
}

struct node * addAtPOS(int data1,int pos,struct node *head){
    struct node * temp3 = head;
    struct node * temp5  = NULL;
    struct node * temp4 = (struct node *)malloc(sizeof(struct node));
    for(int i = 1 ; i < pos ; i++){
        temp3 = temp3->next;
    }
    temp5 = temp3->next;
    temp4->next = temp5;
    temp4->data = data1;
    temp3->next = temp4;
}
 