#include <stdio.h>

int main(int argc, char const *argv[])
{
	// printf("%s\n", "LOOOOOOL");
	
	int  a  = 5;
	int* pa;
	
// char const * ccp; // can repoint pointer
// const char * ccp; // can reassign values via pointer

// REPOINT POINTER PA
#ifdef __cplusplus
	// C++
	pa = &a; 	     // pa points to a
	//pa = a;	     // pa points to a, ERROR int/int* conversion
#else
	// C
	pa = (int*)a;    // pa points to a, no warn explicit conversion
	//pa = a; 		 // pa points to a, WARNING implicit conversion
	pa = &a; 		 
#endif

// REASSIGN VALUES THROUGH POINTER
#ifdef __cplusplus
	*pa = 7; // reassign value at where pa points to
#else
	pa = 7;  // reassign value at where pa points to
#endif

	printf("a = %d\n", a);
	printf("(int)pa = %d\n", (int)pa);
	printf("(int)&a = %d\n", (int)&a);
	printf("(int)&pa = %d\n", (int)&pa);
#ifdef __cplusplus
	printf("*pa = %d\n", *pa);
	printf("%s\n", "$ *pa = 12");
	*pa = 12;
	printf("*pa = %d\n", *pa);
	printf("a = %d\n", a);
#endif

	// for (int i = 0; i < 10000; i++)
	// {
	// 	printf("%d\n", i);

	// }

	return 0;
}