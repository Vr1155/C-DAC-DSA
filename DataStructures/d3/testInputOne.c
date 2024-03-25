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
char empList[ROW][COL];

// Prototypes here 
void extractRecordFromString(char arr[]);
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

// also deleteAtPosition() should give error msg,
// if exact position does not exist in linked list.


// Inorder to generate corefiles in current working directory
// please note that "$" is just to show that this program must be run in
// linux terminal only, although you might look up the windows setup
// run this command before you compile your program:
// $ulimit -c 1024
// This will generate core files in current directory
// for checking whether core file size was set run:
// $ulimit -a
// there you will see the number that you set for core file size.

int main(){

	char str[]={
		"1001,Prabhat Shinde,192834.234:" 
		"1002,Vaibhav Ranashoor,52324.234:" 
		"1003,Vipul Jambhulkar,5234.23:"
		"1004,Mukund Waghmare,5234.234:"
		"1005,Vaibhav Gaikwad,5234.2234"
	};
		
	extractRecordFromString(str);
	/*
	printf("Before loop\n");
	for(int i=0; i<ROW; i++){
		printf("%s\n", empList[i]);
	}
	printf("debugging done\n");
	*/
	for(int i=0; i<ROW; i++){
		addAtEnd(empList, i);
	}

	disp();
	deleteAtPosition();
	disp();
	deleteAtPosition();
	disp();
	deleteAtPosition();
	disp();

}

void extractRecordFromString(char str[]){
	char* token = strtok(str, ":");
	int i=0;
	while (token != NULL && i < ROW) {
		strcpy(empList[i], token);
		token = strtok(NULL, ":");
		i++;
	}
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
	if(position > count)
	{
		printf("Invalid input, no such position exists! discarding input...\n");
		return;
	}
	temp_prev->ptr = temp->ptr;
	temp->ptr=NULL;
	free(temp);
}



