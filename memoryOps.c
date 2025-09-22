#include "headers/memoryOps.h"
#include "headers/data.h"
#include "headers/stackOps.h"

// (x a-addr --)
// store x at a-addr
void store(void)
{
	long temp = pop();
	data[temp] = pop();
}

// (a-addr -- x)
// x is the value stored at location a-addr
void fetch(void)
{
	long temp = pop();
	push(data[temp]);
}

// Reserves one cell of data, which is 8 units
void comma(void)
{
	// takes data_pointer and casts it as a long pointer to address a cell of space
	// pops the top of the stack and places is in the reserved cell
	*(long*)data_pointer = pop();
	// Reserves the cell
	data_pointer += 8;
}
