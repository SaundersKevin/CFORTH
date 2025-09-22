#include <stdio.h>
#include "headers/data.h"

long data[DATA_SPACE];
char * data_pointer = (char*)OFFSET;


// Actual interpereter program
// I love how small it is
// exits on NULL. Sets end of function list as NULL to prevent segmentation fault
// Adding NULL will be implimented elsewhere later, so it shouldn't be needed
// unless I want to add in extra redundancy
void run(void (*funcArr[])(void))
{
	//funcArr[END_OF_PROGRAM] = 0;
	int i = 0;
	while (funcArr[i])
	{
		(*funcArr[i])();
		i++;
	}
}

void parse(void)
{
	// If I was doing this on bare metal I would probably create a buffer that interrupts
	// would write to that would act like a queue

	char * buffer = data_pointer;
	
	scanf("%s", buffer);
}

int main(void)
{
	// Add all words to RAM
	// I could even have this start as calling the equivilent C functions for FORTH words	

	while(1)
	{
		//find at execution_pointer
		//run();
	}

	return 0;
}
