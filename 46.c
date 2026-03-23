#include <stdio.h>
#include <stdlib.h>

// Tree Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure
struct Queue {
    int front, rear, size;
    struct Node* arr[1000];
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->size == 0;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
    q->size++;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    q->size--;
    return q->arr[q->front++];
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);
    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    int i = 1;

    while (i < n) {
        struct Node* current = dequeue(&q);

        // Left child
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);
        printf("%d ", temp->data);

        if (temp->left)
            enqueue(&q, temp->left);

        if (temp->right)
            enqueue(&q, temp->right);
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}