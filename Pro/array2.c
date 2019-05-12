#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int a[10] = {[6] = 100};
	int i = 0;
	
	for(i = 0; i < 10; i++) 
	{
		printf("%d\t",a[i]);
	}
	putchar('\n');
    return 0;
}
//0       0       0       0       0       0       100     0       0       0
