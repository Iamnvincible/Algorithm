#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void MergeSort(int *a,int p,int r);
void Merge(int *a,int p,int q,int r);
int* GenerateArray(int length);
void DisplayArray(int* a,int length);
void Free(int* a,int length);

int main(int argc, char const *argv[])
{
	int length=atoi(argv[1]);
	//printf("%s,%s\n",argv[0],argv[1]);
	int *a=GenerateArray(length);
	DisplayArray(a,length);
	MergeSort(a,0,length-1);
	DisplayArray(a,length);
	//Free(a,length);
	getchar();
	return 0;
}
/*
*������a����p��rλ�õ�Ԫ�ؽ��й鲢����
*a,���飻p����ʼ������±�λ�ã�r������������±�λ�ã�
*/
void MergeSort(int *a,int p,int r){
	int q;
	if(p<r){
		q=(p+r)/2;
		MergeSort(a,p,q);
		MergeSort(a,q+1,r);
		Merge(a,p,q,r);
	}
}
/*
*���������򲿷ֺϲ���ʹ��������
*a�����飻p,q,��һ�����򲿷֣�q+1,r�ڶ������򲿷�
*/
void Merge(int *a,int p,int q,int r){
	int i,j,k;
	int lenleft=q-p+1;
	int lenright=r-q;
	int *left=(int *)malloc(sizeof(int)*(lenleft+1));
	int *right=(int *)malloc(sizeof(int)*(lenright+1));
	for (i = 0; i < lenleft; ++i)
	{
		left[i]=a[p+i];
	}
	for (j = 0; j < lenright; ++j)
	{
		right[j]=a[q+j+1];
	}
	left[i]=65535;
	right[j]=65535;
	i=j=0;
	for (k = p; k <= r; ++k)
	{
		if(left[i]<=right[j]){
			a[k]=left[i++];
			//printf("%d left %d\n",a[k],right[j]);
		}
		else{
			a[k]=right[j++];
			//printf("%d right\n",a[k]);
		}
	}
	free(left);
	free(right);
	//Free(left,lenleft+1);
	//Free(right,lenright+1);
}
int* GenerateArray(int length){
        int *a=(int *)malloc(sizeof(int)*length);
        int i;
		srand(time(NULL));
        for(i = 0; i < length; ++i) {
        	a[i]=rand()%100;
        }
        return a;
}
void DisplayArray(int* a,int length){
	int i;
	for(i = 0; i < length; ++i) {
		printf("%d ",a[i] );
	}
	printf("\n");
}
void Free(int* a,int length){
	int i=length-1;
	while(i>=0){
		free(a+i);
		i=i-1;
	}
	
}

