#include <stdio.h>
#define MAX 20

int adj[MAX][MAX];     // adjacency matrix
int visited[MAX];      // visited array
int queue[MAX];        // for BFS
int front = 0, rear = 0;

// BFS function
void bfs(int start, int n) {
    int i, current;
    for (i = 0; i < n; i++) visited[i] = 0; // reset visited

    printf("BFS starting from vertex %d: ", start);
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// DFS function (recursive)
void dfsUtil(int v, int n) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfsUtil(i, n);
        }
    }
}

void dfs(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0; // reset visited

    printf("DFS starting from vertex %d: ", start);
    dfsUtil(start, n);
    printf("\n");
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected graph
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start, n);
    dfs(start, n);

    return 0;
}
