#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Định nghĩa cấu trúc Stack
typedef struct {
    char data[MAX_SIZE]; // Mảng lưu trữ các ký tự
    int top;             // Vị trí phần tử trên cùng
} Stack;

// Khởi tạo Stack
void initialize(Stack *s) {
    s->top = -1;
}

// Kiểm tra Stack có rỗng không
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Kiểm tra Stack có đầy không
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Thêm phần tử vào Stack
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack đầy, không thể thêm phần tử.\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// Lấy phần tử ra khỏi Stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack rỗng, không thể lấy phần tử.\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

// Lấy phần tử trên cùng mà không xóa khỏi Stack
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

// Hàm kiểm tra sự hợp lệ của cặp dấu ngoặc
bool isValidParentheses(const char *str) {
    Stack s;
    initialize(&s);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        // Nếu là dấu ngoặc mở, đẩy vào Stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        }
        // Nếu là dấu ngoặc đóng, kiểm tra khớp với dấu ngoặc mở trên đỉnh Stack
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s)) {
                return false; // Không có dấu ngoặc mở tương ứng
            }

            char topChar = pop(&s); // Lấy dấu ngoặc mở trên đỉnh Stack

            // Kiểm tra khớp
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false; // Không khớp
            }
        }
    }

    // Nếu Stack rỗng, tất cả dấu ngoặc đều khớp
    return isEmpty(&s);
}

// Hàm chính
int main() {
    char str[MAX_SIZE];

    // Nhập chuỗi từ người dùng
    printf("Nhập chuỗi cần kiểm tra: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0'; // Loại bỏ ký tự newline

    // Kiểm tra và in kết quả
    if (isValidParentheses(str)) {
        printf("Chuỗi hợp lệ.\n");
    } else {
        printf("Chuỗi không hợp lệ.\n");
    }

    return 0;
}