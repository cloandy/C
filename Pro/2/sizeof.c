#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int a = 1;
	char st[100] = "1234567890";
	char st1[]   = "1234567890";
	char * st2 = "1234567890";
	char * p  = NULL;
	
	p = st;

	printf("sizeof(a)  = %ld\t\n ", sizeof(a));
	printf("sizeof(st) = %ld\t strlen(st) = %ld\t\n ",sizeof(st),strlen(st));
	printf("sizeof(st1) = %ld\t strlen(st1) = %ld\t\n ",sizeof(st1),strlen(st1));
	printf("sizeof(st2) = %ld\t strlen(st2) = %ld\t\n ",sizeof(st2),strlen(st2));
	printf("sizeof(p)  = %ld\t  strlen(p) = %ld\t\n",sizeof(p),strlen(p));

	return 0;
}
