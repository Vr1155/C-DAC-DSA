#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
	int id;
	char name[25];
	double salary;
};

int main(){
	// Yet Another way to allocate space for a struct and assign values to struct
	// by using a struct pointer:
	struct Employee *ptr = malloc(sizeof(struct Employee));
	if(ptr != NULL){
		printf("Enter id, name, salary:");
		scanf("%d,%[^,],%lf", &ptr->id, ptr->name, &ptr->salary);
		// using arrow operator to print variables from a struct pointer
		printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);
	}
}
