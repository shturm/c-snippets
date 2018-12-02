#include <stdio.h>

void print(char a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void fwriteend(FILE* f)
{
	char buffer[] = {0};
	fwrite(&buffer, 1,1, f);
}

long int fpsize(FILE* f)
{
// stdio.h
// #define SEEK_SET	0	/* Seek from beginning of file.  */
// #define SEEK_CUR	1	/* Seek from current position.  */
// #define SEEK_END	2	/* Seek from end of file.  */
	
	long int current = ftell(f); // save current position
	fseek(f, 0, SEEK_END); // seek to end, 2nd param is offset
	long int size = ftell(f); // read position = byte count from beginning of file
	// printf("fpsize(): size %ld\n", size);
	
	fseek(f, current, SEEK_SET);

	return size;
}

long int fsize(char const* filename)
{
	FILE* f = fopen(filename,"rb");
	fseek(f, 0, SEEK_END);
	long int size = ftell(f);
	//printf("ftell(f): %ld\n", ftell(f)); // file size in bytes
	fclose(f);
	return size;
}

int main(int argc, char const *argv[])
{
	// char    data[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,0};
	char    data[] = "welcome to kremikovci";
	size_t ndata = sizeof(data)/sizeof(char);
	printf("data to write/read: "); print(data, ndata);
	
	char    buffer[4];
	size_t nbuffer = sizeof(buffer)/sizeof(char);

	FILE* fout = fopen("data.bin", "wb");
	// write in one blow
	size_t written = fwrite(&data, sizeof(char), ndata, fout);
	printf("written %d bytes\n", written);
	fclose(fout);

	FILE* fin = fopen("data.bin", "rb");
	size_t filesize = fpsize(fin);
	printf("filesize to read: %d bytes\n", filesize);
	size_t totalread = 0;
	size_t read = 0; //           objsize       nobj
	while ((read = fread(&buffer, sizeof(char), nbuffer, fin)) > 0)
	{
		totalread += read;
		printf("-------------------------\n");
		printf("totalread: %d bytes\n", totalread);
		printf("read:      %d bytes\n", read);
		printf("cursor:    %ld \n", ftell(fin));
		printf("bytes left:%ld \n", filesize-ftell(fin));
		printf("buffer:    "); print(buffer, nbuffer); // print buffer, or write it somewhere
	}




	return 0;
}