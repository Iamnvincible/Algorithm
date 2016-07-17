#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
void print_arr(int *arr, int n);
void generaterandarr(int *arr, int length);
void insertion_sort(int arr[], int len);
int main() {
	int length =10000;
	int *arr = (int *)malloc(sizeof(int)*length);//申请需要排序的数字存储地址
	generaterandarr(arr, length);
	printf("排序前");
	//print_arr(arr, length);


	LARGE_INTEGER li;
	LONGLONG start, end, freq;
	QueryPerformanceFrequency(&li);
	freq = li.QuadPart;
	QueryPerformanceCounter(&li);
	start = li.QuadPart;
	insertion_sort(arr, length);
	QueryPerformanceCounter(&li);
	end = li.QuadPart;

	double usertime = (double)((end - start) /(double) freq);
	printf("time:%f s\n", usertime);




	printf("排序后");
	//print_arr(arr, length);
	free(arr);
}
void insertion_sort(int arr[], int len) {
	int i, j;//循环变量
	int temp;//临时存储变量
	for (i = 0; i < len; i++)
	{
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];//记录较小的元素
			for (j = i ; j > 0 && arr[j-1] > temp; j--)//当j-1位置的数大于较小数时
			{
				arr[j] = arr[j-1];//当前位置的数等于前一位数
			}
			arr[j] = temp;//当j-1位置的数不大于较小数时，这个位置就是较小数应该在的地方
		}
	}
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
//生成随机数数组
void generaterandarr(int *arr, int length) {
	int i;//循环变量
	srand(time(0));//设置随机函数种子，时间
				   //随机获取0-100的数字
	for (i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
	}
}
