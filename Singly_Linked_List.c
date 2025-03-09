#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

void initList(LinkedList *list) {
    list->head = NULL;
}

int isEmpty(LinkedList *list) {
    return list->head == NULL;
}

void insertAtHead(LinkedList *list, int k) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = list->head;
    list->head = newNode;
}

Node* search(LinkedList *list, int k) {
    Node *current = list->head;
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

void insertBefore(LinkedList *list, Node *p, int k) {
    if (p == NULL) {
        printf("Node is NULL\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = k;
    if (p == list->head) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != p) {
            current = current->next;
        }
        newNode->next = p;
        current->next = newNode;
    }
}

void displayList(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

float averageList(LinkedList *list) {
    Node *current = list->head;
    int sum = 0, count = 0;
    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }
    return (float)sum / count;
}

int main() {
    LinkedList list;
    initList(&list);

    insertAtHead(&list, 10);
    insertAtHead(&list, 20);
    insertAtHead(&list, 30);
    displayList(&list);

    Node *p = search(&list, 20);
    insertAfter(p, 25);
    displayList(&list);

    insertBefore(&list, p, 15);
    displayList(&list);

    printf("Average: %.2f\n", averageList(&list));

    return 0;
}