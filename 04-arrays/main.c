#include <stdio.h>

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void print2(int* a, int n)
{
	int c = 0;
	do
	{
		printf("%d ", *a);
		c++;
		a++;
	} while (c < n);
	printf("\n");
}

void print3(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *a);
		a++;
	}
	printf("\n");
}

void print4(const int* begin, const int* end)
{
	const int* cursor = begin;
	while (cursor != end) printf("%d ", *cursor++);
	printf("\n");
}

void print5(const int* begin, const int* end)
{
	for (const int* cursor = begin; cursor != end; cursor++)
	{
		printf("%d ", *cursor);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4};
	int n = 4;

	const int* begin;
	const int* end;

	// begin = (int*)a; // works
	// begin = &a; // works
	// begin = (int*)&a; // works
	begin = a; // works
	end   = n+begin; // last element is begin+3. begin+4 is past array size

	// &a == &a[0] == (int*)a == (int*)&a // all addresses are the same

	print  (a, n);
	print2((int*)a, n);
	print3((int*)a, n);
	print4((int*)a, (int*)a+n);
	print5(begin, end);

	return 0;
}


// void arrays2()
// {
// 	int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 },
// 		*begin, *end, *cursor;
	
// 	begin = a; // begin points to the first element of array a
// 	end = a + 10; // end points to just after the last element
	
// 	// Print out the contents of the array
// 	cursor = begin;
// 	while (cursor != end) {
// 	std::cout << *cursor << ' '; // Print the element
// 	cursor++; // Increment cursor so it points to the next element
// }

