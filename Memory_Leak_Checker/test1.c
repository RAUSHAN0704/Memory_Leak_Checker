#include "leak.h"
int main()

{
	char * ptr1 = (char *)malloc(10);
	int * ptr2 = (int *)calloc(10, sizeof(int));
ptr2 = (int *)calloc(10, sizeof(int));

ptr2 = (int *)calloc(10, sizeof(int));

ptr2 = (int *)calloc(10, sizeof(int));ptr2 = (int *)calloc(10, sizeof(int));	
	
	float * ptr3 = (float *) calloc(15, sizeof(float));
	char * ptr45 = (char *)malloc(10);
	int * ptr256 = (int *)calloc(10, sizeof(int));
	float * ptr093 = (float *) calloc(15, sizeof(float));
	free(ptr2);
	report_mem_leak();
	return 0;
}
