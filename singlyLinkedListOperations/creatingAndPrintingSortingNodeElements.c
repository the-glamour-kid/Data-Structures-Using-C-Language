#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node * firstLL(int,struct node *);
struct node * formLL(int,struct node *);
struct node * reverse(struct node *,int);
struct node * sorting(struct node *,int);

int main(){

	int num,data1;
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


	ptr = reverse(head,num);
	printf("reverse list is:");
    	for(int i = 0 ; i < num ; i++){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
	ptr2 = sorting(head,num);
	printf("sorted list in ascending is:");
	for(int i = 0 ; i < num ; i++){
        printf("%d ",ptr2->data);
        ptr2 = ptr2->next;
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

// sorting in descending order
struct node * reverse(struct node *head,int num){
    int temp;
    struct node *str1 = NULL;
    str1 = head;
    for(int i = 0 ; i < num ; i++){
        for(int j = 0 ; j < num-i-1 ; j++){
            if ((str1->data) < (str1->next->data)){
                temp = str1->data;
                str1->data = str1->next->data;
                str1->next->data = temp;
            }
            str1 = str1->next;
        }
        str1 = head;
    }
    return head;
}

struct node * sorting(struct node *head,int num){
    int temp;
    struct node *str1 = NULL;
    str1 = head;
    for(int i = 0 ; i < num ; i++){
        for(int j = 0 ; j < num-i-1 ; j++){
            if ((str1->data) > (str1->next->data)){
                temp = str1->data;
                str1->data = str1->next->data;
                str1->next->data = temp;
            }
            str1 = str1->next;
        }
        str1 = head;
    }
    return head;
}