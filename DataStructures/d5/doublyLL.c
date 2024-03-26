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

int main(){
	first = last = NULL;
	int i;
	for(i=0; i<10; i+=2){
		addAtBeg(100+i);
		addAtEnd(200+i+1);
	}
	disp();
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
	}
	else{
		first->prev = New;
		New->next = first;
		first = New;
	}
}

void addAtEnd(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = last = New;
	}
	else{
		New->prev = last;
		last->next = New;
		last = New;
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
	while(temp!= NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void printReverse(){
	Node* temp = last;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
