#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Data{
	int number;
	struct Data* next;
};


typedef struct Data Node;


Node* first = NULL;

Node* createNode(int num){
	Node *ptr = malloc(sizeof(struct Data));
	if(ptr != NULL){
		ptr->number = num;
		ptr->next = NULL;
	}
	return ptr;
}

void addAtBeg(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = New;
	}
	else{
		New->next = first;
		first = New;
	}
}

void disp(){
	Node* temp = first;
	while(temp != NULL){
		printf("Number: %d\n", temp->number);
		temp = temp->next;
	}
}

void addAtEnd(int num){
	Node* New = createNode(num);
	if(first == NULL){
		first = New;
	}
	else{
		Node* temp = first;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = New;
	}
}

void readFromFile(){
	char filedir[100];
	printf("Enter the full path of file to read from (or just filename if in same directory):\n");
	scanf("%s", filedir);

	FILE* fileptr;
	fileptr = fopen(filedir, "r");
	int filecontent[100] = {0}, i = 0;

	if(fileptr == NULL)
	{
		printf("File not found, exiting...");
		return;
	}
	else
	{

		while(!feof(fileptr)){
			fscanf(fileptr, "%d", &filecontent[i]);
			i++;
		}
		fclose(fileptr);
	}

	for(int x =0; x<i-1; x++){
		addAtEnd(filecontent[x]);
	}
}



int main(){
	readFromFile();
	disp();
}
