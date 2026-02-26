#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n, value;
    struct Node *head = NULL, *tail = NULL, *newNode;

    // Read number of nodes
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        // Create new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        // If list is empty
        if (head == NULL) {
            head = tail = newNode;
        } 
        // Insert at end
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Traverse and print the list (forward)
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}