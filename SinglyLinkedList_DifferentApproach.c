#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createEmptyList() {
    return NULL;
}

int isEmpty(Node *head) {
    return head == NULL;
}

Node* insertAtHead(Node *head, int k) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = head;
    return newNode;
}

Node* search(Node *head, int k) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == k) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insertAfter(Node *p, int k) {
    if (p == NULL) {
        printf("Node is NULL\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = p->next;
    p->next = newNode;
}

Node* insertBefore(Node *head, Node *p, int k) {
    if (p == NULL) {
        printf("Node is NULL\n");
        return head;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = k;
    if (p == head) {
        newNode->next = head;
        return newNode;
    } else {
        Node *current = head;
        while (current->next != p) {
            current = current->next;
        }
        newNode->next = p;
        current->next = newNode;
        return head;
    }
}

void displayList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

float averageList(Node *head) {
    Node *current = head;
    int sum = 0, count = 0;
    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }
    return (float)sum / count;
}

int main() {
    Node *head = createEmptyList();

    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtHead(head, 30);
    displayList(head);

    Node *p = search(head, 20);
    insertAfter(p, 25);
    displayList(head);

    head = insertBefore(head, p, 15);
    displayList(head);

    printf("Average: %.2f\n", averageList(head));

    return 0;
}