#include <stdio.h>
#define MAX 10000
#define VEX 5
//�ڽӾ���
int arcs[VEX][VEX] = {
	{ 0,10,MAX,MAX,5 },
	{ MAX,0,1,MAX,2 },
	{ MAX,MAX,0,4,MAX },
	{ MAX,MAX,6,0,MAX },
	{ MAX,3,9,2,0 }
};
int dist[VEX][VEX];
int path[VEX][VEX];
int main() {
	for (int i = 0; i < VEX; i++)
	{
		for (int j = 0; j < VEX; j++)
		{
			dist[i][j] = arcs[i][j];//"����i"��"����j"��·������Ϊ"i��j��Ȩֵ"��
			path[i][j] = j;
		}
	}
	int tmp = 0;
	//ѭ������ÿ������
	for (int k = 0; k < VEX; k++)
	{
		for (int i = 0; i < VEX; i++)
		{
			for (int j = 0; j < VEX; j++)
			{
				//�������k���·���������·�����������dist[i][j]
				tmp = (dist[i][k] == MAX || dist[k][j] == MAX ? MAX : (dist[i][k] + dist[k][j]));
				if (tmp < dist[i][j]) {
					dist[i][j] = tmp;
					path[i][j] = path[i][k];
				}

			}
		}
	}
	for (int i = 0; i < VEX; i++)
	{
		for (int j = 0; j < VEX; j++)
		{
			if (dist[i][j] == MAX)
				printf("- ");
			else
				printf("%d ", dist[i][j]);
		}
		printf("\n");
	}
}