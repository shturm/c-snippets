#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	char* line  = "one,two,three,four,five";
	char* delim = ",";
	char *token, *cp, *cp2, *token2;
	char** save;

	printf("==================\n");
	printf("line: %s\n", line);
	printf("===== strtok =====\n");
	cp = strdup(line);
	token = strtok(cp, delim);
	printf("%s\n", token);
	while((token = strtok(NULL, delim)) != NULL)
	{
		printf("%s\n", token);
	}

	printf("===== strtok_r =====\n");
	cp2 = strdup(line);
	token2 = strtok_r(cp2, delim, save);
	printf("%s (next: %s)\n", token2, *save);
	while((token2 = strtok_r(NULL, delim, save)) != NULL)
	{
		printf("%s (next: %s)\n", token2, *save);
	}



	return 0;
}