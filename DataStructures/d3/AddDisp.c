#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
	// Pointer for storing address
	struct Employee *ptr;
};

// using typedef:
typedef struct Employee Node;

// this is the head of the linked list:
Node* first = NULL;

Node* createNode(){
	Node *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		printf("Enter id, name, salary:");


		// Notice how we are reading the string! using , as a delimitor.
		scanf("%d, %[^,], %lf", &ptr->id, ptr->name, &ptr->salary);
		// pointing the pointer ptr (next Node pointer) to itself.
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




int main(){
	addAtBeg();
	addAtBeg();
	addAtBeg();
	disp();
	addAtBeg();
	addAtBeg();
	disp();
}
