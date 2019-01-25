#include <stdio.h>


int main(int argc, char const *argv[])
{
	FILE* fp = popen("/bin/ls -lsa ~/", "r");
	char path[1035];
	// fflush(p);

	if (fp == NULL) {
	    printf("Failed to run command\n" );
	    exit(1);
	  }

	  /* Read the output a line at a time - output it. */
	  while (fgets(path, sizeof(path)-1, fp) != NULL) {
	    printf("%s", path);
	  }

	// printf("ftell(fp): %ld\n", ftell(fp));

	pclose(fp);
	return 0;
}