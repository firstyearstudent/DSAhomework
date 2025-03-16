#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Định nghĩa cấu trúc Queue
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Hàm khởi tạo Queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Hàm kiểm tra Queue rỗng
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Hàm enqueue (thêm phần tử vào Queue)
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Hàm dequeue (lấy phần tử ra khỏi Queue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    Node* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

// Hàm in Queue
void printQueue(Queue* q) {
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    int n, value;
    printf("Nhap so luong phan tu trong Queue: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        enqueue(&q, value);
    }

    printf("Queue: ");
    printQueue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue sau khi dequeue: ");
    printQueue(&q);

    return 0;
}