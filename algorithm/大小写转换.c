#include <stdio.h>

void UpperTo(char *str);
void LowerTo(char *str);
int main(int argc,char **argv)
{
	char str[100];
	printf("请输入要转换的字母序列\n");
	scanf("%s",str);
	
	printf("你输入的字母序列为%s\n",str);

	printf("--------开始转化为大写字母序列----------\n");
	UpperTo(str);
	printf("转换的大写字母序列为:%s\n",str);
	printf("--------结束转化为大写字母序列----------\n");
	printf("--------开始转化为小写字母序列----------\n");
	LowerTo(str);
	printf("转换的小写字母序列为:%s\n",str);
	printf("--------结束转化为小写字母序列----------\n");
	
	return 0;
}

//A:65 a:97 32
void UpperTo(char *str)
{
	int i = 0;
	char ch;
	while((*str) != '\0')
	{
		if(((*str) >= 97) && (((*str) <= (97 + 23))))
		{
			*str = (*str) - 32 ;
		}
		str ++;
	}
}

//A:65 a:97 32
void LowerTo(char *str)
{
	int i = 0;
	char ch;
	while((*str) != '\0')
	{
		if(((*str) >= 65) && (((*str) <= (65 + 23))))
		{
			*str = (*str) + 32 ;
		}
		str ++;
	}
}


