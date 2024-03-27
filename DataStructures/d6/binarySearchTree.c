#include<stdio.h>
#include<stdlib.h>

typedef struct Test{
	int data;
	struct Test *left, *right;
} Node;

Node *createNode(int);

void insert(int);
void disp();
void preOrder(Node*);
void inOrder(Node*);
void postOrder(Node*);

Node* root = NULL;

int main(){
	int arr[] = {40, 30, 60, 10, 30, 50, 70, 5, 15, 25, 35, 45, 55, 65, 75};
	int i;
	for(i=0; i<15; ++i){
		insert(arr[i]);
	}
	disp();
}

void insert(int num){
	Node *prev = NULL, *temp = root;
	Node* New = createNode(num);
	while(temp != NULL){
		prev = temp;
		if(num < temp->data){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}
	}
	if(prev == NULL){
		root = New;
	}
	else if(num < prev->data){
		prev->left = New;
	}
	else{
		prev->right = New;
	}
}

Node* createNode(int num){
	Node* New = malloc(sizeof(Node));
	if(New != NULL){
		New->data = num;
		New->left = New->right = NULL;
	}
	return New;
}

void disp(){
	printf("Pre-Order:  ");
	preOrder(root);
	printf("\nIn-Order:   ");
	inOrder(root);
	printf("\nPost-Order: ");
	postOrder(root);
	printf("\n=========================================\n");
}

void preOrder(Node *root){
	if(root != NULL){
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node* root){
	if(root != NULL){
		preOrder(root->left);
		printf("%d ", root->data);
		preOrder(root->right);
	}	
}


void postOrder(Node* root){
	if(root != NULL){
		preOrder(root->left);
		preOrder(root->right);
		printf("%d ", root->data);
	}	
}
