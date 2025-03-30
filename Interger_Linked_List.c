//Bài 1
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;
    int priority; // Ưu tiên
    struct Node* next;
} Node;

// Hàm tạo một node mới
Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

/* Bài 2
void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    Node *sorted = NULL;
    Node *current = *head;

    while (current != NULL) {
        Node *next = current->next;
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    *head = sorted;
}*/

/*Bài 3
void appendList(Node** head1, Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    Node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}*/

/*Bài 4
void insertListAtPosition(Node** head1, Node* head2, int position) {
    if (*head1 == NULL || position < 0) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    Node* temp = *head1;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vi tri vuot qua do dai danh sach!\n");
        return;
    }

    Node* nextNode = temp->next;
    temp->next = head2;

    while (head2->next != NULL) {
        head2 = head2->next;
    }
    head2->next = nextNode;
}*/

/*Bài 5
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}*/

// Hàm thêm một phần tử vào hàng đợi ưu tiên
void enqueue(Node** head, int data, int priority) {
    Node* newNode = createNode(data, priority);
    if (*head == NULL || (*head)->priority > priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Hàm lấy phần tử có ưu tiên cao nhất ra khỏi hàng đợi
int dequeue(Node** head) {
    if (*head == NULL) {
        printf("Hang doi rong!\n");
        return -1;
    }
    Node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

// Hàm in hàng đợi
void printQueue(Node* head) {
    while (head != NULL) {
        printf("%d (Priority: %d) -> ", head->data, head->priority);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    enqueue(&head, 10, 2);
    enqueue(&head, 20, 1);
    enqueue(&head, 30, 3);
    printQueue(head);

    printf("Dequeue: %d\n", dequeue(&head));
    printQueue(head);

    return 0;
}