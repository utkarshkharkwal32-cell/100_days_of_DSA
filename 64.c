#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Enqueue function
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// BFS function
void bfs(int adj[MAX][MAX], int n, int s) {
    int i;

    enqueue(s);
    visited[s] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// Main function
int main() {
    int n, adj[MAX][MAX], i, j, s;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &s);

    // Initialize visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    bfs(adj, n, s);

    return 0;
}
