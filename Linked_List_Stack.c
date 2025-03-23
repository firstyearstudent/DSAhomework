#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Định nghĩa cấu trúc Stack
typedef struct {
    Node* top;
} Stack;

// Hàm khởi tạo Stack
void initStack(Stack* s) {
    s->top = NULL;
}

// Hàm kiểm tra Stack rỗng
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Hàm push (thêm phần tử vào Stack)
void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Hàm pop (lấy phần tử ra khỏi Stack)
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    Node* temp = s->top;
    int poppedValue = temp->data;
    s->top = s->top->next;
    free(temp);
    return poppedValue;
}

// Hàm in Stack
void printStack(Stack* s) {
    Node* current = s->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    int n, value;
    printf("Nhap so luong phan tu trong Stack: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        push(&s, value);
    }

    printf("Stack: ");
    printStack(&s);

    printf("Popped: %d\n", pop(&s));
    printf("Stack sau khi pop: ");
    printStack(&s);

    return 0;
}