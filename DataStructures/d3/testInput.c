
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
//prototypes here 
//

Node* createNode();
void addAtBeg();
void disp();
void addAtEnd();


// TODO:
// rewrite all functions,
// so that you take inputs from a string array
// create a linked list from those inputs
// only take positions of those nodes from user
// and then take positions for deletions of those nodes from user.

int main(){
	char str[5][]={"1001,Prabhat,192834.234:", "1002,Vaibhav,52324.234", "1003,Vipul,5234.23","1004,Mukund,5234.234","1005,Joseph,5234.2234"};
	
	for(int i=0; i<5; i++){
		addAtEnd(str, i);
	}
	disp();
	deleteAtPosition();
	disp();
	deleteAtPosition();
	disp();
	deleteAtPosition();
	disp();
}


Node* createNode(char* arr, int i){
	Node *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
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

void addAtEnd(char* arr, int i){
	Node* New = createNode(arr, i);
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


