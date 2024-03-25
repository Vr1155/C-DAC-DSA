#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef ROW
#define ROW 5
#endif

#ifndef COL
#define COL 50
#endif

struct Employee{
	int id;
	char name[25];
	double salary;
	struct Employee *ptr;
};

typedef struct Employee Node;

Node* first = NULL;

//prototypes here 
Node* createNode();
void disp();
void addAtEnd(char a[ROW][COL], int i);
void deleteAtPosition();

// TODO:
// rewrite all functions,
// so that you take inputs from a string array
// create a linked list from those inputs
// only take positions of those nodes from user
// and then take positions for deletions of those nodes from user.

// also note that deleteAtPosition() should only delete the exact position only!
// if the entered position is greater than count of linked list then it should show error msg.

int main(){
	char str[5][50]={
		"1001,Prabhat Shinde,192834.234", 
		"1002,Vaibhav Ranashoor,52324.234", 
		"1003,Vipul Jambhulkar,5234.23",
		"1004,Mukund Waghmare,5234.234",
		"1005,Vaibhav Gaikwad,5234.2234"
	};
	
	for(int i=0; i<ROW; i++){
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


Node* createNode(char arr[ROW][COL], int i){
	Node *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		char* token;

		token = strtok(arr[i], ",");
		ptr->id = atoi(token);

		token = strtok(NULL, ",");
		strcpy(ptr->name, token);

		token = strtok(NULL, ",");
		ptr->salary = strtod(token, NULL);
	
		ptr->ptr = NULL;

		printf("New Node: ID: %d Name: %s Sal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
	return ptr;
}

void disp(){
	Node* temp = first;
	while(temp != NULL){
		printf("Id: %d, Name: %s, Salary:%.2lf\n", temp->id, temp->name, temp->salary);
		temp = temp->ptr;
	}
}

void addAtEnd(char arr[ROW][COL], int i){
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



