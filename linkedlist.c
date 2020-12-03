#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct linknode {
	int data;
	void* next;
};

static struct linknode *list;

struct linknode *create_node(int value){
	struct linknode* ptr;
	
	ptr = (struct linknode*)malloc(sizeof(struct linknode));
	
	ptr->data = value;
	ptr->next = NULL;
	
	return ptr;
}

int insertDataLast(int value){
	struct	linknode *nodePtr;
	struct	linknode *srchPtr;
	
	nodePtr = create_node(value);
	if (nodePtr == NULL)
	{
		printf("memory allocation error!\n");
		return -1;
	}
	
	if (list == NULL)
	{
		list = nodePtr;
	}
	else
	{
		srchPtr = list;
		while(srchPtr->next != NULL){
			srchPtr = (struct linknode*)srchPtr->next;
		}
		srchPtr->next = nodePtr;
	}

	
	return 0;
}

void print_list(void){
	struct linknode *ptr = list;
	int i;
	
	while (ptr != NULL && ptr->next != NULL){
		printf("%i \n", ptr->data);
		ptr = ptr->next;
	}
}

void print_node(int n){
	struct linknode *ptr = list;
	int i=0;
	while (ptr != NULL && ptr->next != NULL){
		if ( i == n){
			printf("%i'th data : %i\n",i, ptr->data);
			return;
		}
		i++;
	}
		printf("no data\n"); 
}
