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
		scanf("%d, %[^,], %lf", &ptr->id, &ptr->name, &ptr->salary);
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


int main(){
	addAtEnd();
	disp();
	addAtEnd();
	disp();
	addAtEnd();
	disp();
	addAtEnd();
	disp();
	addAtEnd();
	disp();
}
