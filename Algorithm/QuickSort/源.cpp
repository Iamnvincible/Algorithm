#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quick_sort(int *s, int l, int r) {
	if (l < r) {
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			//���������ҵ�һ��С��x����
			while (i < j&&s[j] >= x) {
				j--;
			}
			//�ҵ��Ժ󣬷���s[i]���棬i++
			if (i < j) {
				s[i++] = s[j];
			}
			//���������ҵ�һ������x����
			while (i < j&&s[i] < x)
			{
				i++;
			}
			//�ҵ��Ժ󣬷���s[j]���棬j--
			if (i < j) {
				s[j--] = s[i];
			}
		}
		//��ɵ�һ�����򣬰ѻ�������s[i]
		s[i] = x;
		quick_sort(s, l, i - 1);
		quick_sort(s, i + 1, r);
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
	int length = atoi(argv[1]);
	//printf("%s,%s\n",argv[0],argv[1]);
	int *a = GenerateArray(length);
	DisplayArray(a, length);
	quick_sort(a, 0, length - 1);
	DisplayArray(a, length);
	//Free(a,length);
	getchar();
	return 0;
}