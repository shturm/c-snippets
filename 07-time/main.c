#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	clock_t start, end;
	
	start = clock();
	for (int i = 0; i < 9000000; ++i)
	{
		/* code */
	}
	end = clock();

	printf("CLOCKS_PER_SEC: %ld\n", CLOCKS_PER_SEC);

	printf("time (cpu) to calculate: %ld\n", end-start);
	printf("time (sec) to calculate: %f\n", ((double)(end-start))/CLOCKS_PER_SEC);

	printf("==========================\n");
	printf("\n");

	
	return 0;
}