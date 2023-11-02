#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /* 무한대 (연결이 없는 경우) */

typedef struct GraphNode {
    int vertex;
    int weight;
    struct GraphNode* next;
} GraphNode;

typedef struct GraphType {
    int n;                 // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES]; /* 시작정점으로부터의 최단경로 거리 */
int found[MAX_VERTICES];    /* 방문한 정점 표시 */
int previous[MAX_VERTICES]; /* 이전 정점 저장 */

int choose(int distance[], int n, int found[]) {
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

void add_edge(GraphType* g, int start, int end, int weight) {
    GraphNode* new_node = (GraphNode*)malloc(sizeof(GraphNode));
    new_node->vertex = end;
    new_node->weight = weight;
    new_node->next = g->adj_list[start];
    g->adj_list[start] = new_node;
}

void shortest_path(GraphType* g, int start) {
    int i, u, w;
    for (i = 0; i < g->n; i++) {
        distance[i] = INF;
        found[i] = FALSE;
        previous[i] = -1; // Initialize previous array
    }
    distance[start] = 0;

    for (i = 0; i < g->n - 1; i++) {
        u = choose(distance, g->n, found);
        found[u] = TRUE;
        GraphNode* current = g->adj_list[u];
        while (current != NULL) {
            w = current->vertex;
            if (!found[w] && distance[u] + current->weight < distance[w]) {
                distance[w] = distance[u] + current->weight;
                previous[w] = u; // Update previous vertex
            }
            current = current->next;
        }
         
        printf("Distance array after step %d:\n", i + 1); // 데구 9번
        for (int j = 0; j < g->n; j++) {
            printf("distance[%d]: %d\n", j, distance[j]);
        }
        printf("\n");
    }
}

void print_path(int start, int end) {
    if (start == end) {
        printf("%d ", start);
        return;
    }
    print_path(start, previous[end]);
    printf("%d ", end);
}

void print_shortest_paths(GraphType* g, int start) { // 데구 8버
    printf("Shortest paths from vertex %d:\n", start);
    for (int i = 0; i < g->n; i++) {
        if (i != start) {
            printf("To vertex %d: ", i);
            print_path(start, i);
            printf(" (Distance: %d)\n", distance[i]);
        }
    }
}

int main(void) {
    GraphType g;
    g.n = 6;

    for (int i = 0; i < g.n; i++) {
        g.adj_list[i] = NULL;
    }

    add_edge(&g, 0, 1, 50);
    add_edge(&g, 0, 2, 45);
    add_edge(&g, 0, 3, 10);
    add_edge(&g, 1, 2, 10);
    add_edge(&g, 1, 3, 15);
    add_edge(&g, 2, 4, 30);
    add_edge(&g, 3, 0, 20);
    add_edge(&g, 3, 4, 15);
    add_edge(&g, 4, 1, 20);
    add_edge(&g, 4, 2, 35);
    add_edge(&g, 5, 4, 3); // 정점 5 추가

    shortest_path(&g, 0);
    print_shortest_paths(&g, 0); // Print shortest paths
    return 0;
}