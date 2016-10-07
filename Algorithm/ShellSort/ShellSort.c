#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shellsort1(int a[], int n)
{
	int i, j, gap;

	for (gap = n / 2; gap > 0; gap /= 2) //步长  
		for (i = 0; i < gap; i++)        //直接插入排序  
		{
			for (j = i + gap; j < n; j += gap)
				if (a[j] < a[j - gap])
				{
					int temp = a[j];
					int k = j - gap;
					while (k >= 0 && a[k] > temp)
					{
						a[k + gap] = a[k];
						k -= gap;
					}
					a[k + gap] = temp;
				}
		}
}
void shellsort(int* a, int len) {
	int gap, i, j;
	int temp;
	for (gap = len / 2; gap > 0; gap /= 2) {
		for (i = gap; i < len; i++) {
			temp = a[i];
			for (j = i - gap; j >= 0 && a[j] > temp; j -= gap)
				a[j + gap] = a[j];
			a[j + gap] = temp;
		}
	}
}
int* GenerateArray(int length) {
	int *a = (int *)malloc(sizeof(int)*length);
	int i;
	srand(time(NULL));
	for (i = 0; i < length; ++i) {
		a[i] = rand() % 100;
	}
	return a;
}
void DisplayArray(int* a, int length) {
	int i;
	for (i = 0; i < length; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	int length = 9;
	int *a = GenerateArray(length);
	DisplayArray(a, length);
	shellsort1(a, length);
	DisplayArray(a, length);
	return 0;
}