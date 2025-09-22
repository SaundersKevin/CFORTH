#include "headers/executionOps.h"
#include "headers/stackOps.h"
#include "headers/data.h"

void execute(void)
{
	// pops the top of the stack and adds OFFSET
	// retrieves the pointer stored at that location
	// casts pointer as a function pointer and executes it
	((void(*)(void))(*(pop() + OFFSET)))();
}
