#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	//int a[][3] = {{1,2,3},{4,5,6}};
	int a[][3] = {1,2,3,4,5,6};
	int i,j;
	for(i = 0; i < 2; i++)
		for(j = 0; j < 3; j++)
			printf("%d\t",a[i][j]);
	putchar('\n') ;
    return 0;
}
