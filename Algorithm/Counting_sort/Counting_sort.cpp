#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
void counting_sort(int *init_arr, int *sorted_arr, int n);
void print_arr(int *arr, int n);
int main(int argc, char **argv) {
	int length = 100;//Ҫ��������ָ���
	int i;//ѭ������
	int *arr = (int *)malloc(sizeof(int)*length);//������Ҫ��������ִ洢��ַ
	int *sorted_arr = (int *)malloc(sizeof(int)*length);//�������������ִ洢��ַ
	srand(time(0));//��������������ӣ�ʱ��
	//�����ȡ0-100������
	for (i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
	}
	printf("����ǰ����");
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

	printf("���������");
	print_arr(sorted_arr, length);
	//�ͷ�ָ��
	free(arr);
	free(sorted_arr);
	return 0;
}
//�����������Ԫ��
void print_arr(int *arr, int n) {
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//������������0-100��֮�������
void counting_sort(int *init_arr, int *sorted_arr, int n) {
	int *count_arr = (int *)malloc(sizeof(int) * 100);//�������ڼ�������ռ�
	int i, j, k;//ѭ������
	//��ʼ��
	for (k = 0; k < 100; k++)
	{
		count_arr[k] = 0;
	}
	//��һ��������ÿ������number���ֵĴ���,�ڼ�������[number]+1;
	for (i = 0; i < n; i++)
	{
		count_arr[init_arr[i]]++;
	}
	//�ڶ�������ǰ����ۼӼ������飬��ֵ�����ֵ���λ�����������С���м�������ô������־����ڶ���λ��
	for (k = 1; k < 100; k++)
	{
		count_arr[k] += count_arr[k - 1];
	}
	//������������
	for (j = 0; j < n; j++) {  
		sorted_arr[--count_arr[init_arr[j]]] = init_arr[j];
	}
}
