#include <stdio.h>


int main(int argc, char const *argv[])
{
	FILE* p = popen("ls -lsa ~/", "wrt");
	fflush(p);
	// printf("ftell(p): %ld\n", ftell(p));
	return 0;
}