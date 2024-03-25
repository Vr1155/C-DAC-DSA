
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
	struct Employee *ptr;
};


typedef struct Employee Node;


Node* first = NULL;

Node* createNode(){
	Node *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d, %[^,], %lf", &ptr->id, ptr->name, &ptr->salary);
		ptr->ptr = NULL;
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
	return ptr;
}

void addAtBeg(){
	Node* New = createNode();
	if(first == NULL){
		first = New;
	}
	else{
		New->ptr = first;
		first = New;
	}
}

void disp(){
	Node* temp = first;
	while(temp != NULL){
		printf("Id: %d, Name: %s, Salary:%.2lf\n", temp->id, temp->name, temp->salary);
		temp = temp->ptr;
	}
}

void addAtEnd(){
	Node* New = createNode();
	if(first == NULL){
		first = New;
	}
	else{
		Node* temp = first;
		while(temp->ptr != NULL){
			temp = temp->ptr;
		}
		temp->ptr = New;
	}
}

void addAtPosition(){
	int position;
	printf("Enter the position where you want to insert Node:\n");
	scanf("%d", &position);
	if(position == 1){
		addAtBeg();
		return;
	}

	Node* New = createNode();

	if(first == NULL){
		first = New;
	}
	else{
		Node* temp = first;
		int count = 1;
		while(temp->ptr != NULL && count < position-1){
			temp = temp->ptr;
			count++;
		}
		New->ptr = temp->ptr;
		temp->ptr=New;
	}
}


void deleteAtPosition(){
	if(first == NULL){
		printf("Nothing to delete! Exiting...");
		return;
	}
	int position;
	printf("Enter the position where you want to delete Node:\n");
	scanf("%d", &position);
	if(position == 1){
		Node* temp = first;
		first = first->ptr;
		temp->ptr = NULL;
		free(temp);
		return;
	}
	Node* temp_prev = NULL;
	Node* temp = first;
	int count = 1;
	while(temp->ptr != NULL && count < position){
		temp_prev = temp;
		temp = temp->ptr;
		count++;
	}
	temp_prev->ptr = temp->ptr;
	temp->ptr=NULL;
	free(temp);
}



int main(){
	addAtPosition();
	addAtPosition();
	addAtPosition();
	addAtPosition();
	addAtPosition();
	disp();
	deleteAtPosition();
	disp();
	deleteAtPosition();
	disp();
	deleteAtPosition();
	disp();
}
