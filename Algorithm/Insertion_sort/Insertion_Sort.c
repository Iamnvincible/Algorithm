#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Insertion_Sort(int* a,int length){
	int i,j,key;
	for (i = 1; i < length; ++i)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1]=a[j];
			--j;
		}
		a[j+1]=key;
	}
	return 0;

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
		i--;
	}
	
}
int main(int argc, char const *argv[])
{
	int length=30;
	int * a=GenerateArray(length);
	DisplayArray(a,length);
	Insertion_Sort(a,length);
	DisplayArray(a,length);	
	Free(a,length);
	getchar();
	return 0;
}