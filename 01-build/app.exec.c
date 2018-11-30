#include <stdio.h>
#include "app.core.h"

int main(int argc, char** args)
{
	for (int i = 0; i < argc-1; i++)
	{
		printf("%s\n", *args++);
	}

	const char* a = "asdf";
	printf("%s\n", a);
	return 0;
}