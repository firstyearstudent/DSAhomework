#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Định nghĩa cấu trúc Book
typedef struct {
    int maSoSach;
    char tenSach[50];
    long donGia;
} Book;

// Định nghĩa cấu trúc Stack
typedef struct {
    Book data[MAX_SIZE];
    int top;
} Stack;

// Khởi tạo Stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Kiểm tra Stack có rỗng không
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Kiểm tra Stack có đầy không
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Thêm một phần tử vào Stack
void push(Stack *stack, Book book) {
    if (isFull(stack)) {
        printf("Stack đầy, không thể thêm phần tử.\n");
        return;
    }
    stack->data[++stack->top] = book;
}

// Lấy một phần tử ra khỏi Stack
Book pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack rỗng, không thể lấy phần tử.\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

// Hàm tính đơn giá trung bình của các cuốn sách trong Stack
double averagePrice(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack rỗng, không có sách để tính toán.\n");
        return 0.0;
    }

    long total = 0;
    int count = 0;
    Stack tempStack;
    initStack(&tempStack);

    // Lấy các phần tử từ Stack gốc và tính tổng đơn giá
    while (!isEmpty(stack)) {
        Book book = pop(stack);
        total += book.donGia;
        count++;
        push(&tempStack, book);
    }

    // Đẩy lại các phần tử vào Stack gốc
    while (!isEmpty(&tempStack)) {
        push(stack, pop(&tempStack));
    }

    return (double)total / count;
}

int main() {
    Stack bookStack;
    initStack(&bookStack);

    // Thêm các cuốn sách vào Stack
    Book book1 = {1, "Lap Trinh C", 100000};
    Book book2 = {2, "Cau Truc Du Lieu", 150000};
    Book book3 = {3, "Giai Thuat", 200000};

    push(&bookStack, book1);
    push(&bookStack, book2);
    push(&bookStack, book3);

    // Tính và hiển thị đơn giá trung bình
    double avgPrice = averagePrice(&bookStack);
    printf("Don gia trung binh cua cac cuon sach trong Stack: %.2lf\n", avgPrice);

    return 0;
}