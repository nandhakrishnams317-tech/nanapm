/*
NAME: NANDHA KRISHNA M S
Roll No: CS09
EX NO: 14
DATE: 26-09-2026

**********Graphs**********

AIM: Implementation of graphs and graph traversals.
*/

/* **********ALGORITHM**********

Step 1: Start.
Step 2: Declare a graph using an adjacency matrix and initialize all elements to 0.
Step 3: Read the number of vertices and edges.
Step 4: Read each edge and set the corresponding adjacency matrix elements to 1.
Step 5: Read the starting vertex.
Step 6: Initialize all vertices as unvisited for BFS.
Step 7: Mark the starting vertex as visited and insert it into the queue.
Step 8: Remove a vertex from the queue and display it.
Step 9: Check all adjacent vertices. If a vertex is connected and unvisited, mark it as visited and insert it into the queue.
Step 10: Repeat Steps 8 and 9 until the queue becomes empty.
Step 11: Initialize all vertices as unvisited for DFS.
Step 12: Mark the starting vertex as visited and display it.
Step 13: Visit each adjacent unvisited vertex recursively and display it.
Step 14: Repeat the DFS process until no adjacent unvisited vertices remain.
Step 15: Display the BFS and DFS traversal results.
Step 16: Stop.

/* **********SOURCE CODE********** */


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph {
    int n;
    int matrix[MAX][MAX];
};

void initialize(struct Graph *g, int n) {
    g->n = n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->matrix[i][j] = 0;
        }
    }
}

void insertEdge(struct Graph *g, int u, int v) {
    g->matrix[u][v] = 1;
    g->matrix[v][u] = 1;
}

void bfs(struct Graph *g, int start) {
    int visited[MAX] = {0};
    int q[MAX], front = 0, rear = 0;

    visited[start] = 1;
    q[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = q[front++];
        printf("%d ", current);

        for (int i = 0; i < g->n; i++) {
            if (g->matrix[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }

    printf("\n");
}

void dfsVisit(struct Graph *g, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < g->n; i++) {
        if (g->matrix[vertex][i] == 1 && !visited[i]) {
            dfsVisit(g, i, visited);
        }
    }
}

void dfs(struct Graph *g, int start) {
    int visited[MAX] = {0};

    printf("DFS Traversal: ");
    dfsVisit(g, start, visited);
    printf("\n");
}

int main() {
    struct Graph g;
    int n, e, u, v, start;

    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1) return 0;

    initialize(&g, n);

    printf("Enter number of edges: ");
    if (scanf("%d", &e) != 1) return 0;

    for (int i = 0; i < e; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &u, &v);
        insertEdge(&g, u, v);
    }

    printf("Enter start vertex for traversal: ");
    if (scanf("%d", &start) != 1) return 0;

    bfs(&g, start);
    dfs(&g, start);

    return 0;
}


/* **********OUTPUT**********

Enter number of vertices: 5
Enter number of edges: 5
Enter edge (source destination): 0 1
Enter edge (source destination): 0 2
Enter edge (source destination): 1 3
Enter edge (source destination): 1 4
Enter edge (source destination): 2 4
Enter start vertex for traversal: 0

BFS Traversal: 0 1 2 3 4
DFS Traversal: 0 1 3 4 2

*/