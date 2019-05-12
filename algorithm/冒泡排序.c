#include <stdio.h>
void ShowArray(int array[],int length);
void BubbleSort(int array[], int length);

int main(int argc, char **argv)
{
	int array[] = {1,3,5,7,9,0,2,4,6,8};
	//sizeof得到的是整个数组所占内存大小，并不是数组的个数
	int length = sizeof(array)/sizeof(array[0]);
	printf("array[] 数组的大小为%d\n",length);
	
	printf("------冒泡排序算法---------\n");
	printf("冒泡排序前的数组顺序：\n");
	ShowArray(array,length);
	BubbleSort(array,length);
	printf("冒泡排序后的数组顺序：\n");
	ShowArray(array,length);

	return 0;
}

void ShowArray(int array[],int length)
{
	int i;
	for(i = 0; i < length; i++)
		printf("%d\t",array[i]);
	putchar('\n');
}

void BubbleSort(int array[], int length)
{
	int i,j;
	int temp;
	for(i = 1; i < length; i++)
	{
		for(j = 0; j < length - i ; j++)
		{
			if(array[j] > array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}


