#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
void counting_sort(int *init_arr, int *sorted_arr, int n);
void print_arr(int *arr, int n);
int main(int argc, char **argv) {
	int length = 100;//要排序的数字个数
	int i;//循环变量
	int *arr = (int *)malloc(sizeof(int)*length);//申请需要排序的数字存储地址
	int *sorted_arr = (int *)malloc(sizeof(int)*length);//申请排序后的数字存储地址
	srand(time(0));//设置随机函数种子，时间
	//随机获取0-100的数字
	for (i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
	}
	printf("排序前数组");
	print_arr(arr, length);


	LARGE_INTEGER li;
	LONGLONG start, end, freq;
	QueryPerformanceFrequency(&li);
	freq = li.QuadPart;
	QueryPerformanceCounter(&li);
	start = li.QuadPart;
	counting_sort(arr, sorted_arr, length);

	QueryPerformanceCounter(&li);
	end = li.QuadPart;

	double usertime = (double)((end - start) / (double)freq);
	printf("time:%f s\n", usertime);

	printf("排序后数组");
	print_arr(sorted_arr, length);
	//释放指针
	free(arr);
	free(sorted_arr);
	return 0;
}
//输出数组所有元素
void print_arr(int *arr, int n) {
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//计数排序，排序0-100的之间的数字
void counting_sort(int *init_arr, int *sorted_arr, int n) {
	int *count_arr = (int *)malloc(sizeof(int) * 100);//申请用于计数数组空间
	int i, j, k;//循环变量
	//初始化
	for (k = 0; k < 100; k++)
	{
		count_arr[k] = 0;
	}
	//第一步，计算每个数字number出现的次数,在计数数组[number]+1;
	for (i = 0; i < n; i++)
	{
		count_arr[init_arr[i]]++;
	}
	//第二步，从前向后累加计数数组，数值即数字的排位（比这个数字小的有几个，那么这个数字就排在多少位）
	for (k = 1; k < 100; k++)
	{
		count_arr[k] += count_arr[k - 1];
	}
	//第三步，排序
	for (j = 0; j < n; j++) {  
		sorted_arr[--count_arr[init_arr[j]]] = init_arr[j];
	}
}
