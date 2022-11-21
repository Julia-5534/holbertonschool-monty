#include "monty.h"

int pop() 
{
	int item; 
	if(top == -1) // Checking Array is empty or not. 
	{
		printf("Underflow"); 
		return -1;  
	} 
	item = stack[top]; 
	top -= 1; //	top = top - 1 
	return item; 
}
