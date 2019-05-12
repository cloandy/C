#include <stdio.h>

int main()
{
	int i,j;
	for(i = 0; i< 3; i++)
	{
		for(j = 0; j < 6; j++)
		{
			if(j == 4)
				goto loop;
			printf("i = %d and j = %d\n",i,j);
		}
	}

loop:printf("end!\n");
	return 0;
}
