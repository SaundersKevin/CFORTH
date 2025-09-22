#include <stdio.h>

int main()
{
	char character = 'a';
	int integer = 97;
	long long_integer = 97;
	printf("char: %lu\nint: %lu\nlong: %lu",sizeof(character),sizeof(integer),sizeof(long_integer));
}
