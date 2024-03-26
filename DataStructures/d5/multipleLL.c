
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef MAX
#define MAX 5
#endif

struct Employee {
	int id;
	struct Employee *ptr;	//Pointer for storing 
};
typedef struct Employee Node;

Node* createNode(int);
void addAtBeg(Node**, int);
void addAtEnd(Node**, int);
void addAtPos(Node**, int, int);
void deleteAtPos(Node**, int);
void disp(Node*);

int main(){ // local variable first
	Node* arr[MAX] = {NULL};
	int i, j;
	for(i=0; i<MAX; i++){
		for(int j=0; j<(i+1)*10; j++){
			addAtEnd(&arr[i], (i+1)*10 + j+1);
		}
		disp(arr[i]);
	}
}

void deleteAtPos(Node** first, int pos){
	if(*first == NULL){
		printf("List is empty...Nothing to do\n");
		return;
	}
	Node* temp = *first;
	if(pos == 1){
		*first = (*first)->ptr;
	}
	else{
		int cnt = 1;
		Node* prev = NULL;
		while(temp != NULL && cnt < pos){
			prev = temp;
			temp = temp->ptr;
			cnt++;
		}
		if(temp == NULL){
			printf("%d: No such position\n", pos);
			return;
		}
		prev->ptr = temp->ptr;
	}
	free(temp);
}

void addAtPos(Node** first, int data, int pos){
	Node* New = createNode(data);
	if(*first == NULL)
		*first = New;
	else{
		int cnt = 1;
		Node* temp = *first;
		while(temp->ptr != NULL && cnt < pos-1){ // traversing to the last node
			temp = temp ->ptr;
			cnt++;
		}
		New->ptr = temp->ptr;
		temp->ptr = New;
	}
}


void addAtEnd(Node** first, int data){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		Node* temp = *first;
		while(temp->ptr != NULL){ // traversing to the last node
			temp = temp->ptr;
		}
		temp->ptr = New;
	}
}

void addAtBeg(Node** first, int data){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		New->ptr = *first;
		*first = New;
	}
}

void disp(Node* temp){
	printf("List: ");
	while(temp != NULL){
		printf("%d ", temp->id);
		temp = temp->ptr;
	}
	printf("\n----------------------------------------\n");
}

Node* createNode(int data){
	Node* ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		ptr->id = data;
		ptr->ptr = NULL;
	}
	return ptr;
}
