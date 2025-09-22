#include "headers/dictionaryOps.h"
#include "headers/stackOps.h"
#include "headers/data.h"
#include "headers/executionOps.h"

long * wordlist_pointer = OFFSET;

void retrieve()
{
	
}

void create(void)
{
	// find next space in buffer, after next word
	// space characters are represented as 32
	//(char*)&(data[execution_pointer]) + 6;
	// I NEED TO CHANGE THIS TO INCREMENTING BY CHARACTERS
	// CURRENTLY IT IS ASSUMING THE BUFFER IS WRITTEN BY CELLS, NOT UNITS
	// AND IS ASSUMING THE SAME FOR WORD NAMES
	// IN PROGRESS DOING SO ^
	// COUNT NEEDS TO MAKE THE POINTERS MATCH UP
	int count = 0;
	while (*execution_pointer == 32)
		(*execution_pointer)++;
	while (*execution_pointer != 32 && *execution_pointer != 0)
	{
		*data_pointer++ = *execution_pointer++; // copy over the name
		count++;
	}
	*data_pointer++ = 0; // I am going to treat this as pushing the address
	count++;
	while (count < 32)
	{
		data_pointer++;
		count++;
	}
	wordlist_pointer = (long*)data_pointer;
}

void allot(void)
{
	// pop top of stack
	// allocate or disallocate pop units of data space
}

void variable(void)
{
	

	// create function

	// allocate
}

void constant(void)
{
	
}
