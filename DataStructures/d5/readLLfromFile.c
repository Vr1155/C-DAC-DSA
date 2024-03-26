#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef MAX
#define MAX 5
#endif

// Instructors final code:
// This is the type of questions you can expect in data structures lab exam
// reading from a string using sscanf() and strtok(), reading from a file using fopens() and fscanf()


struct Employee {
	int id;
	char name[25];
	double salary;
	struct Employee *ptr;	//Pointer for storing next node
};
typedef struct Employee Node;

Node* createNode(FILE*);
void addAtBeg(Node**, FILE*);
void addAtEnd(Node**, FILE*);
void addAtPos(Node**, FILE*, int);
void deleteAtPos(Node**, int);
void disp(Node*);

int main(){
	Node* first = NULL;
	FILE* fPtr = fopen("myData.txt", "r");
	if(fPtr != NULL){
		while(!feof(fPtr)){
			addAtEnd(&first, fPtr);
		}
		disp(first);
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

void addAtPos(Node** first, FILE* data, int pos){
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


void addAtEnd(Node** first, FILE* data){
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

void addAtBeg(Node** first, FILE* data){
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
	printf("List:\n");
	while(temp != NULL){
		printf("Id: %d\tName:%s\tSalary: %.2f\n", temp->id, temp->name, temp->salary);
		temp = temp->ptr;
	}
	printf("\n----------------------------------------\n");
}

Node* createNode(FILE* fPtr){
	Node* ptr = NULL;

	if(!feof(fPtr)){
		ptr = malloc(sizeof(struct Employee));
		int ret = fscanf(fPtr, "%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		ptr->ptr = NULL;
		if(ret == -1){
			free(ptr);
			ptr=NULL;
		}
	}
	return ptr;
}
