#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
typedef struct Node {
    int vertex, weight;
    struct Node* next;
} Node;

// Min heap node
typedef struct {
    int vertex, dist;
} HeapNode;

Node* adj[MAX];

// Function to add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Simple priority queue (min heap)
HeapNode heap[MAX * MAX];
int heapSize = 0;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(int v, int d) {
    heap[++heapSize].vertex = v;
    heap[heapSize].dist = d;

    int i = heapSize;
    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode root = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= heapSize && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right <= heapSize && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }

    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w); // directed graph
        // If undirected, also add: addEdge(v, u, w);
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;
    push(source, 0);

    while (heapSize > 0) {
        HeapNode top = pop();
        int curr = top.vertex;
        int currDist = top.dist;

        if (currDist > dist[curr])
            continue;

        Node* temp = adj[curr];
        while (temp != NULL) {
            int next = temp->vertex;
            int weight = temp->weight;

            if (dist[curr] + weight < dist[next]) {
                dist[next] = dist[curr] + weight;
                push(next, dist[next]);
            }

            temp = temp->next;
        }
    }

    // Output distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}
