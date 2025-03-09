#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element items[MAX_SIZE];
    int size;
} PriorityQueue;

void initPriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

int isFull(PriorityQueue *pq) {
    return pq->size == MAX_SIZE;
}

void enqueue(PriorityQueue *pq, int data, int priority) {
    if (isFull(pq)) {
        printf("Priority Queue is full!\n");
        return;
    }
    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    int i = pq->size - 1;
    while (i >= 0 && pq->items[i].priority > newElement.priority) {
        pq->items[i + 1] = pq->items[i];
        i--;
    }
    pq->items[i + 1] = newElement;
    pq->size++;
}

int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    int data = pq->items[0].data;
    for (int i = 1; i < pq->size; i++) {
        pq->items[i - 1] = pq->items[i];
    }
    pq->size--;
    return data;
}

void displayPriorityQueue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return;
    }
    for (int i = 0; i < pq->size; i++) {
        printf("(%d, %d) ", pq->items[i].data, pq->items[i].priority);
    }
    printf("\n");
}

int main() {
    PriorityQueue pq;
    initPriorityQueue(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    displayPriorityQueue(&pq);

    printf("Dequeued: %d\n", dequeue(&pq));
    displayPriorityQueue(&pq);

    return 0;
}