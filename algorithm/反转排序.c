#include <stdio.h>
void ShowArray(int array[],int length);
void ReverSort(int array[], int length);

int main(int argc, char **argv)
{
	int array[] = {1,3,5,7,9,0,2,4,6,8};
	//sizeof得到的是整个数组所占内存大小，并不是数组的个数
	int length = sizeof(array)/sizeof(array[0]);
	printf("array[] 数组的大小为%d\n",length);
	
	printf("------冒泡排序算法---------\n");
	printf("冒泡排序前的数组顺序：\n");
	ShowArray(array,length);
	ReverSort(array,length);
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

void ReverSort(int array[], int length)
{
	int i;
	int temp;
	for(i = 0; i < length/2; i++)
	{
		temp = array[i];
		array[i] = array[length -i -1];
		array[length -i -1] = temp;
	}
}


