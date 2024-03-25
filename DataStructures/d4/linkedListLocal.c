#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee {
	int id;
	struct Employee *next;	// Pointer for storing next address.
};

typedef struct Employee Node;

Node* createNode(int);
void addAtBeg(Node**, int);
void addAtEnd(Node**, int);
void addAtPos(Node**, int, int);
void deleteAtPos(Node**, int);
void disp(Node*);

// This modified code was written by instructor,
// screenshots were posted on group chat
// This code is very similar to previous ones,
// except this one eliminates all global variables.


int main() {

	// Head of linked list:
	Node *first = NULL;
	// Notice how we are passing head of linked list to every function,
	// this helps eliminate a global variable which was head of LL.
	// It also helps us use the same functions for multiple different linked lists
	// with different head pointers.
	//
	// Apart from that we are also passing Node data in parameters.
	//
	// If you notice, we are passing address of head pointer
	// this is because all function arguments are pass by value in C/C++
	// therefore in order to change that exact head pointer,
	// we have to pass a pointer to that pointer.
	
	addAtBeg(&first, 1001);
	addAtEnd(&first, 1002);
	addAtEnd(&first, 1003);
	disp(first);
	// Here we are also passing position as parameter:
	addAtPos(&first, 1004, 2);
	addAtPos(&first, 1005, 3);
	addAtPos(&first, 1010, 5);
	disp(first);
	deleteAtPos(&first, 10);
	disp(first);
	deleteAtPos(&first, 4);
	disp(first);
}

Node* createNode(int data){
	Node* ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		ptr->id = data;
		ptr->next = NULL;
	}
	return ptr;
}

void addAtBeg(Node** first, int data){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		New->next = *first;
		*first = New;
	}
}

void addAtEnd(Node** first, int data){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		Node* temp = *first;
  		// traversing to the last node
		while(temp->next != NULL){
			temp = temp->next;

		}
		temp->next = New;
	}
}

void addAtPos(Node** first, int data, int pos){
	Node* New = createNode(data);
	if(*first == NULL){
		*first = New;
	}
	else{
		int cnt = 1;
		Node* temp = *first;
		while(temp->next != NULL && cnt < pos-1){
			temp = temp->next;
			cnt++;
		}
		New->next = temp->next;
		temp->next = New;
	}
}

void deleteAtPos(Node** first, int pos){
	if(*first == NULL){
		printf("List is empty... Nothing to do\n");
		return;
	}
	Node* temp = *first;
	if(pos == 1){
		*first = (*first)->next;
	}
	else{
		int cnt = 1;
		Node* prev = NULL;
		while(temp!=NULL && cnt < pos){
			prev = temp;
			temp = temp->next;
			cnt++;
		}
		if(temp == NULL){
			printf("%d: No such position\n", pos);
			return;
		}
		prev->next = temp->next;
	}
	free(temp);
}

void disp(Node* temp){
	while(temp != NULL){
		printf("Id: %d\n", temp->id);
		temp = temp->next;
	}
	printf("------------------------------------------\n");
}


