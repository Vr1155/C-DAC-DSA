#include<stdio.h>
#include<stdlib.h>

typedef struct Test{
	int data;
	struct Test *prev, *next;
} Node;

Node *first, *last;

Node *createNode(int);
void addAtBeg(int);
void addAtEnd(int);
void disp();
void printForward();
void printReverse();
void deleteAtData(int);

int main(){
	first = last = NULL;
	int i;
	for(i=0; i<10; i+=2){
		addAtBeg(100+i);
		addAtEnd(200+i+1);
	}
	disp();
///*
	deleteAtData(100);
	printf("After deleting 100\n");
	disp();
	deleteAtData(108);
	printf("After deleting 108\n");
	disp();
	deleteAtData(209);
	printf("After deleting 209\n");
	disp();
	deleteAtData(1000);
	printf("After deleting 1000\n");
	disp();

//*/
}

Node* createNode(int num){
	Node* New = malloc(sizeof(Node));
	if(New!=NULL){
		New->data = num;
		New->prev = New->next = NULL;
	}
	return New;
}

void addAtBeg(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
		New->next = New->prev = New;
	}
	else{
		first->prev = New;
		New->next = first;
		first = New;
		first->prev = last;
		last->next = first;
	}
}

void addAtEnd(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
		New->next = New->prev = New;
	}
	else{
		New->prev = last;
		last->next = New;
		last = New;
		first->prev = last;
		last->next = first;
	}
}

void disp(){
	printf("Forward: ");
	printForward();
	printf("Reverse: ");
	printReverse();
	printf("\n-------------------------------\n");
}

void printForward(){
	Node* temp = first;
	printf("%d ", temp->data);
	temp= temp->next;
	while(temp!= first){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void printReverse(){
	Node* temp = last;
	printf("%d ", temp->data);
	temp = temp->prev;
	while(temp != last){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

void deleteAtData(int data){
	if(first == NULL){
		printf("Nothing to delete! Returning...\n");
		return;
	}
	Node* temp = first->next;
	Node* temp_prev = first;

	while(temp != first && temp->data != data){
		temp_prev = temp;
		temp = temp->next;
	}
	if(temp == first && temp->data != data){
		printf("That data does not exist! Returning...\n");
		return;
	}
	else if(temp == first){
		temp->next->prev = last;
		last->next = temp->next;
		first = temp->next;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else if(temp == last){
		temp_prev->next = first;
		first->prev = temp_prev;
		last = temp_prev;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else{
		temp->next->prev = temp_prev;
		temp_prev->next = temp->next;
		temp->next = NULL;
		temp->prev = NULL;
	}
	free(temp);
}
