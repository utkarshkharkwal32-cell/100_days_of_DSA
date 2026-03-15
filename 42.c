#include <stdio.h>
#include <stdlib.h>

// Stack Node
struct StackNode {
    int data;
    struct StackNode* next;
};

void push(struct StackNode** top, int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct StackNode** top) {
    if (*top == NULL) return -1;
    struct StackNode* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

// Queue Node
struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

void enqueue(struct Queue* q, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    struct QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return data;
}

// Function to reverse the queue
void reverseQueue(struct Queue* q) {
    struct StackNode* stack = NULL;

    // Step 1: Queue -> Stack
    while (q->front != NULL) {
        push(&stack, dequeue(q));
    }

    // Step 2: Stack -> Queue
    while (stack != NULL) {
        enqueue(q, pop(&stack));
    }
}

int main() {
    int n, val;
    struct Queue q = {NULL, NULL};

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    reverseQueue(&q);

    // Print reversed queue
    struct QueueNode* temp = q.front;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next ? " " : ""));
        temp = temp->next;
    }

    return 0;
}