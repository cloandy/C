#include <stdio.h>
void Show(int num);

int main(int argc, char **argv)
{
	int num;
	printf("请输入你要打印的三角形的层数:\t");
	scanf("%d",&num);
	putchar('\n');
	printf("--------开始打印菱形------");
	putchar('\n');
	Show(num);
	printf("--------结束打印菱形------");
	putchar('\n');


	return 0;
}

void Show(int num)
{
	int i,j;
	int cnt = 0;
	for(i = 1; i <= num; i ++)//控制层数,指明位于第几层
	{
		for(j = 0; j < num - i; j++)//控制空格的个数
			printf(" ");
		while(cnt != (i * 2 -1))
		{
			printf("*");
			cnt ++;
		}
		cnt = 0;
		putchar('\n');
	}

	for(i = num - 1; i >= 1; i --)//控制层数,指明位于第几层
    {
        for(j = 0; j < num - i; j++)//控制空格的个数
            printf(" ");
        while(cnt != (i * 2 -1))
        {
            printf("*");
            cnt ++;
        }
        cnt = 0;
        putchar('\n');
    }
}

