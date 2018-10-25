#include <stdio.h>


int main(int arg, char* argc[])
{

	printf("Hello assignment1.\n");

	int a;
	int* b;
	long c;
	double* d;
	char** e;
	printf("%d \n",sizeof(int));
	printf("%d \n",sizeof(int*));
	printf("%d \n",sizeof(long));
	printf("%d \n",sizeof(double*));
	printf("%d \n",sizeof(char**));
	return 0;

}
