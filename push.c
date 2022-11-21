#include "monty.h"

void push(int item) 
{ 
	if(top == MAX-1) // Checking Array is full or not. 
	{ 
		printf("Overflow\n"); 
	} 
	else 
	{
		top += 1; // top = top + 1 
		stack[top] = item; 
	} 
	return ; 
}
