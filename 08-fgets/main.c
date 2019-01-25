#include <stdio.h>

#define MAX 1000

int main(int argc, char const *argv[])
{
	FILE* f = fopen("file.txt", "r");

	char line[MAX];
	while(fgets(line, MAX, f) > 0)
	{
		printf(line);
	}
	return 0;
}