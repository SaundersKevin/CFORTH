#include "headers/dictionaryOps.h"
#include "headers/stackOps.h"
#include "headers/data.h"
#include "headers/executionOps.h"

long * wordlist_pointer = OFFSET;

// (--)
// parses the next token as a name and writes it to the dictionary
// name is given the function pointer NULL, which I will treat as returning the address
// as data in my run() program
// execution pointer is incremented to parse and make the interpereter skip over name
void create(void)
{
	// find next space in buffer, after next word
	// space characters are represented as 32
	int count = 0;
	while (*execution_pointer == 32)
	{
		execution_pointer++;
	}
	while (*execution_pointer != 32 && *execution_pointer != 0)
	{
		*data_pointer = *execution_pointer; // copy over the name
		data_pointer++;
		execution_pointer++;
		count++;
	}
	*data_pointer++ = 0; // null ends the string
	count++;
	while (count < 32)
	{
		data_pointer++;
		count++;
	}
	wordlist_pointer = (long*)data_pointer;
	*(long*)data_pointer = 0;
	data_pointer += 8;
}

// (n --)
// reserves n units of address space
// if n is less that zero, release |n| address space
// since I address units, not cells, I do not need to scale anything
void allot(void)
{
	// pops the top of the stack and allocates that much data units
	// I do not have to push anything onto the stack for this
	// implimnting HERE might make this a little more useful, or just use it to
	// address more data for variables
	// They can point to the reserved address space
	data_pointer += pop();
}

// Varaible acts like create but with [8 ALLOT] called after
// 8, because that is the size of a cell
// I am assuming that data_pointer is aligned at this point in time
void variable(void)
{
	create();
	push(8);
	allot();
}

// (x --)
// creates a variable with value x
void constant(void)
{
	int temp = pop();
	variable();
	// wrtie temp to data_pointer
	// casts as a long to address a full cell
	*((long*)data_pointer - 1) = temp;
}
