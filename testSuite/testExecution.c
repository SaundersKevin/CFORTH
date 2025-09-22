#include <stdio.h>
#include "headers/executionOps.h"
#include "headers/data.h"
#include "headers/stackOps.h"

long data[DATA_SPACE];

void test(void)
{
	printf("Test passed!");
}

int main(void)
{
	data[0] = (long)test;
	push(0);
	execute();
}
