#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
void print_arr(int *arr, int n);
void generaterandarr(int *arr, int length);
void insertion_sort(int arr[], int len);
int main() {
	int length =10000;
	int *arr = (int *)malloc(sizeof(int)*length);//������Ҫ��������ִ洢��ַ
	generaterandarr(arr, length);
	printf("����ǰ");
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




	printf("�����");
	//print_arr(arr, length);
	free(arr);
}
void insertion_sort(int arr[], int len) {
	int i, j;//ѭ������
	int temp;//��ʱ�洢����
	for (i = 0; i < len; i++)
	{
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];//��¼��С��Ԫ��
			for (j = i ; j > 0 && arr[j-1] > temp; j--)//��j-1λ�õ������ڽ�С��ʱ
			{
				arr[j] = arr[j-1];//��ǰλ�õ�������ǰһλ��
			}
			arr[j] = temp;//��j-1λ�õ��������ڽ�С��ʱ�����λ�þ��ǽ�С��Ӧ���ڵĵط�
		}
	}
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
//�������������
void generaterandarr(int *arr, int length) {
	int i;//ѭ������
	srand(time(0));//��������������ӣ�ʱ��
				   //�����ȡ0-100������
	for (i = 0; i < length; i++)
	{
		arr[i] = rand() % 100;
	}
}
