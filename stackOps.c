#include "headers/stackOps.h"
#include "headers/data.h"

int stack_pointer = DATA_SPACE - RETURN_SPACE;
int return_pointer = DATA_SPACE;

void push(long var)
{
	stack_pointer--;
	data[stack_pointer] = var;
}

long pop(void)
{
	return data[stack_pointer++];
}

long peek(void)
{
	return data[stack_pointer];
}

void push_r(long var)
{
	return_pointer--;
	data[return_pointer] = var;
}

long pop_r(void)
{
	return data[return_pointer++];
}

void drop(void)
{
	stack_pointer++;
}

void dup(void)
{
	data[stack_pointer - 1] = data[stack_pointer];
	stack_pointer--;
}

void swap(void)
{
	int temp = data[stack_pointer];
	data[stack_pointer] = data[stack_pointer + 1];
	data[stack_pointer + 1] = temp;
}

void over(void)
{
	push(data[stack_pointer + 1]);
}
