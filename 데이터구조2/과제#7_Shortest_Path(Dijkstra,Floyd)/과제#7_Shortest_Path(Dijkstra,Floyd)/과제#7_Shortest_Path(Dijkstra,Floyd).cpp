#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define MAX1 100
#define INF 1000000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];

}GraphType;
int distance[MAX_VERTICES];/* 시작정점으로부터의 최단경로 거리 */  // dijkstra
int found[MAX_VERTICES];		/* 방문한 정점 표시 */

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void print_status(GraphType* g)  // 다이제스트라
{
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("        found:    ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");

	
}


void shortest_path(GraphType* g, int start) // 다이제스트라
{
	int i, u, w;
	for (i = 0; i < g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;    /* 시작 정점 방문 표시 */
	distance[start] = 0;
	for (i = 0; i < g->n - 1; i++) {
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}
}





int A[MAX_VERTICES][MAX_VERTICES]; // floyd
int n = -1;
void printA(GraphType* g) {
	int i, j;
	printf("=======================\n");
	printf("A%d\n",n++);
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF)
				printf(" * ");
			else printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("=======================\n");
}


void floyd(GraphType* g)
{
	int a[MAX1];
		
	int i, j, k;
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];
	printA(g);

	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++)
			for (j = 0; j < g->n; j++)
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
		printA(g);
	}
	for (int b = 0; b < g->n; b++) {
		a[b] = 0;
		for (int c = 0; c < g->n; c++) {
			if(A[b][c]!= INF)
				a[b] += A[b][c];
		}
	}
	printf("floyd 가중치의 합은");
	for (int q = 0; q < g->n; q++) {
		printf("%d: %d ",q+1,a[q]);
	}
	
}
int main(void)
{
	GraphType g = { 6,
	{{ 0,  10, INF, 30,   100,  INF },
	{ INF,  0,  50, INF,   INF,  INF },
	{ INF,  INF,  0, INF,   10,  5 },
	{ INF,  INF,  20, 0,   INF,  15 },
	{ INF,  INF,  INF, 60,   0,  INF },
	{ INF,  INF,  INF, INF,  INF,  0 }}
	};
	printf("여기서부터 다이제스트라\n");
	shortest_path(&g, 0);
	int a = 0;
	for (int i = 0; i < g.n; i++) {
		a += distance[i];
	}
	printf("가중치 합은: %d\n", a);
	printf("여기서부터 floyd\n");
	floyd(&g);
	return 0;
}