#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for BFS with horizontal distance
struct QNode {
    struct Node* node;
    int hd;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node** queue = malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    // Queue for BFS
    struct QNode* queue = malloc(1000 * sizeof(struct QNode));
    int front = 0, rear = 0;

    // Map: HD range offset (to handle negative index)
    int map[2000][100];   // stores nodes
    int count[2000] = {0};

    int offset = 1000; // shift for negative HD
    int minHD = 1000, maxHD = 1000;

    queue[rear++] = (struct QNode){root, offset};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        map[hd][count[hd]++] = curr->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, hd - 1};

        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, hd + 1};
    }

    // Print vertical order
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    free(queue);
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}