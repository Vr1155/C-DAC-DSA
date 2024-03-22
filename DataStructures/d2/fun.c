#include<stdio.h>

// learning about control flow of functions

void fun();
void funOne();
void funTwo();
void funThree();


int main(){
	printf("1. in main()\n");
	fun();
	printf("2. in main()\n");
}

void fun(){
	printf("1. in fun()\n");
	funOne();
	printf("2. in fun()\n");
}

void funOne(){
	printf("1. in funOne()\n");
	funTwo();
	printf("2. in funOne()\n");
}

void funTwo(){
	printf("1. in funTwo()\n");
	funThree();
	printf("2. in funTwo()\n");
}

void funThree(){
	printf("funthree() called.\n");
}

















