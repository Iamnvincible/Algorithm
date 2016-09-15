#include <stdio.h>
#define MAX 10000
//�ڽӾ���
int arcs[5][5] = { {0,10,MAX,MAX,5},
					{MAX,0,1,MAX,2},
					{MAX,MAX,0,4,MAX},
					{MAX,MAX,6,0,MAX},
					{MAX,3,9,2,0}
};
//�Ѿ�������·���Ķ���
int s[] = { 0,0,0,0,0 };
//���·����ǰ��
int path[] = { 0,0,0,0,0 };
//��ԭ�㵽���������㵱ǰ���·������
int dist[5] = {};
int main()
{
	//��ʼ��dist[]
	for (int i = 0; i < 5; i++)
	{
		dist[i] = arcs[0][i];
	}
	int k = 0;
	s[0] = 1;
	int min = MAX;
	for (int i = 0; i < 5; i++)
	{
		min = MAX;
		for (int j = 0; j < 5; j++)
		{
			if (dist[j] < min && s[j] == 0)
			{
				min = dist[j];
				k = j;//���k���Ѿ���ȡ�������·��
			}
		}
		s[k] = 1;
		int tmp = MAX;
		//�������·��
		for (int j = 0; j < 5; j++)
		{
			tmp = arcs[k][j] == MAX ? MAX : (min + arcs[k][j]);
			if (s[j] == 0 && (tmp < dist[j]))
			{
				dist[j] = tmp;
				path[j] = k;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", dist[i]);
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", path[i]);
	}

}