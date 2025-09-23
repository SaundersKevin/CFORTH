#include "headers/dictionaryOps.h"
#include <stdio.h>
#include <assert.h>
#include "headers/data.h"
#include "headers/executionOps.h"
#include "headers/stackOps.h"

long data[DATA_SPACE];
char * data_pointer = (char*)OFFSET;
char * execution_pointer = (char*)OFFSET;

void write(char string[],char* buffer)
{
	int i = 0;
	while (string[i])
	{
		*(buffer + i) = string[i];
		i++;
	}

	assert(*buffer == 'n');
}

int main()
{
	// Loading a word into the buffer
	char * buffer = data_pointer + 10;
	write("name var const",buffer);

	// set execution_pointer to read from the beginning of the buffer
	execution_pointer = buffer;

	create();

	printf("Testing CREATE: ");

	assert(*(char*)data == 'n');
	assert(*((char*)data + 1) == 'a');
	assert(*((char*)data + 2) == 'm');
	assert(*((char*)data + 3) == 'e');
	assert(data_pointer == (char*)OFFSET + 32 + 8);

	printf("PASSED\n");

	push(8);
	allot();

	printf("Testing ALLOT: ");

	assert(data_pointer == (char*)OFFSET + 32 + 16);

	printf("PASSED\n");

	variable();

	printf("Testing VARIABLE: ");

	assert(*((char*)data + 32 + 16) == 'v');
	assert(*((char*)data + 32 + 17) == 'a');
	assert(*((char*)data + 32 + 18) == 'r');

	printf("PASSED\n");

	push(8);

	printf("Testing CONSTANT: ");

	constant();

	printf("PASSED\n");

	assert(*((char*)data + 32 + 16 + 32 + 16) == 'c');
	assert(*((char*)data + 32 + 16 + 32 + 17) == 'o');
	assert(*((char*)data + 32 + 16 + 32 + 18) == 'n');
	assert(*((char*)data + 32 + 16 + 32 + 19) == 's');
	assert(*((char*)data + 32 + 16 + 32 + 20) == 't');
	assert(*((char*)data + 32 + 16 + 32 + 16 + 32) == 0);
	assert(*((char*)data + 32 + 16 + 32 + 16 + 32 + 8) == 8);
	
	printf("All tests passed");
}
