#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Định nghĩa cấu trúc Stack
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Khởi tạo Stack
void initialize(Stack *s) {
    s->top = -1;
}

// Kiểm tra Stack có rỗng không
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Kiểm tra Stack có đầy không
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Thêm phần tử vào Stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack đầy, không thể thêm phần tử.\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// Lấy phần tử ra khỏi Stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack rỗng, không thể lấy phần tử.\n");
        return -1;
    }
    return s->data[(s->top)--];
}

// Hàm chuyển đổi số nguyên sang hệ nhị phân
void decimalToBinary(int n) {
    Stack s;
    initialize(&s);

    // Chuyển đổi số nguyên sang nhị phân và đẩy vào Stack
    while (n > 0) {
        push(&s, n % 2);
        n = n / 2;
    }

    // In kết quả từ Stack
    printf("Số nhị phân: ");
    while (!isEmpty(&s)) {
        printf("%d", pop(&s));
    }
    printf("\n");
}

// Hàm chính
int main() {
    int n;

    // Nhập số nguyên từ người dùng
    printf("Nhập số nguyên: ");
    scanf("%d", &n);

    // Chuyển đổi và in ra số nhị phân
    decimalToBinary(n);

    return 0;
}