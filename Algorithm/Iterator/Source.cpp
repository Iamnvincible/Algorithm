/*
���ڽӾ����ʾ��ͼ��DFS��BFS
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))
//�ڽӾ����ʾ��ͼ�����ݽṹ
typedef struct _graph {
	char vexs[MAX];//���㼯��
	int vexnum;//������
	int edgnum;//����
	int martix[MAX][MAX];//�ڽӾ���
}Graph,*PGraph;
int get_position(Graph g, char ch) {
	int i;
	for (i = 0; i < g.vexnum; i++)
		if (g.vexs[i] == ch)
			return i;
	return -1;
}

/*ʹ�þ��󴴽�ͼ*/
Graph* create_graph() {
	char vexs[] = { '0','1','2','3','4','5','6' };
	char edges[][2] = {
		{'0','2'},
		{'0','3'},
		{'0','5'},
		{'1','2'},
		{'2','3'},
		{'4','6'},
		{'5','6'}
	};
	int vlen = LENGTH(vexs);
	int elen = LENGTH(edges);
	int i, p1, p2;
	Graph* pG;
	//���붥�����ͱ���
	if ((pG = (Graph*)malloc(sizeof(Graph))) == NULL)
		return NULL;
	memset(pG, 0, sizeof(Graph));
	pG->vexnum = vlen;
	pG->edgnum = elen;
	for (i = 0; i < pG->vexnum; i++) {
		pG->vexs[i] = vexs[i];
	}
	for (i = 0; i < pG->edgnum; i++) {
		p1 = get_position(*pG, edges[i][0]);
		p2 = get_position(*pG, edges[i][1]);
		pG->martix[p1][p2] = 1;
		pG->martix[p2][p1] = 1;
	}
	return pG;
}
/*
*���ض���v�ĵ�һ���ڽӶ�������������򷵻�-1
*/
int first_vertex(Graph G, int v) {
	int i;
	if (v<0 || v>(G.vexnum - 1))
		return -1;
	for (i = 0; i < G.vexnum; i++) {
		if (G.martix[v][i] == 1)
			return i;
	}
	return -1;
}

/*���ض���v�����w����һ���ڽӶ����������ʧ���򷵻�-1*/
int next_vertix(Graph G, int v, int w) {
	int i;
	if (v<0 || v>(G.vexnum - 1) || w<0 || w>(G.vexnum - 1))
		return -1;
	for (i = w + 1; i < G.vexnum; i++) {
		if (G.martix[v][i] == 1)
			return i;
	}
	return -1;
}
/*
*���������������ͼ���ݹ�ʵ��
*/
void DFS(Graph G, int i, int *visited) {
	int w;
	visited[i] = 1;
	printf("%c ", G.vexs[i]);
	for (w = first_vertex(G, i); w >= 0; w = next_vertix(G, i, w)) {
		if (!visited[w])
			DFS(G, w, visited);
	}
}

void DFSTraverse(Graph G) {
	int i;
	int visited[MAX];

	for (i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	printf("DFS:");
	for (i = 0; i < G.vexnum; i++) {
		if (!visited[i])
			DFS(G, i, visited);
	}
	printf("\n");
}
/*�����������*/
void BFS(Graph G) {
	int head = 0;
	int rear = 0;
	int queue[MAX];//����
	int visited[MAX];//������ʱ��
	int i, j, k;
	for (i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	printf("BFS:");
	for (i = 0; i < G.vexnum; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			printf("%c ", G.vexs[i]);
			queue[rear++] = i;//�������
		}
		printf(" =while= ");
		while (head != rear) {
			j = queue[head++];
			for (k = first_vertex(G, j); k > 0; k = next_vertix(G, j, k)) {
				printf(" -%d- ", k);
				if (!visited[k]) {
					visited[k] = 1;
					printf("%c ", G.vexs[k]);
					queue[rear++] = k;
				}
			}
		}
	}
	printf("\n");
}
int main() {
	Graph* pG;
	pG = create_graph();
	DFSTraverse(*pG);
	BFS(*pG);
	return 0;
}