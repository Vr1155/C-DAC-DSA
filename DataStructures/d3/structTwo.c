#include<stdio.h>

struct Employee{
	int id;
	// make sure your char array is big enough
	// if its exactly same size as name
	// there will be no null terminator
	// and it will print garbage value
	// till it finds a null character.
	char name[25];
	double salary;
};

int main(){
	struct Employee var = {1001, "Veera Prathapa Reddy", 98723.34};
	
	struct Employee *ptr = &var;
	
	printf("ID: %d\tName: %s\tSal:%.2lf\n", var.id, var.name, var.salary);

	// using struct pointer to print variables:
	printf("ID: %d\tName: %s\tSal:%.2lf\n", (*ptr).id, (*ptr).name, (*ptr).salary);
	// using arrow operator to print variables from a struct pointer
	printf("ID: %d\tName: %s\tSal:%.2lf\n", ptr->id, ptr->name, ptr->salary);

}
