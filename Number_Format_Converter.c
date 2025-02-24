#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Định nghĩa cấu trúc Stack
typedef struct {
    void* data[MAX_SIZE]; // Mảng lưu trữ các phần tử (kiểu void*)
    int top;              // Vị trí phần tử trên cùng
    size_t elementSize;   // Kích thước của mỗi phần tử
} Stack;

// Khởi tạo Stack
void initialize(Stack *s, size_t elementSize) {
    s->top = -1;
    s->elementSize = elementSize;
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
void push(Stack *s, void* element) {
    if (isFull(s)) {
        printf("Stack đầy, không thể thêm phần tử.\n");
        return;
    }
    s->top++;
    s->data[s->top] = malloc(s->elementSize); // Cấp phát động
    memcpy(s->data[s->top], element, s->elementSize); // Sao chép dữ liệu
}

// Lấy phần tử ra khỏi Stack
void* pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack rỗng, không thể lấy phần tử.\n");
        return NULL;
    }
    void* element = s->data[s->top]; // Lấy phần tử trên cùng
    s->top--;
    return element;
}

// Hàm chuyển đổi số nguyên sang hệ số bất kỳ
void convertNumber(int number, int base) {
    if (base < 2 || base > 36) {
        printf("Hệ số không hợp lệ. Hệ số phải từ 2 đến 36.\n");
        return;
    }

    Stack s;
    initialize(&s, sizeof(char)); // Stack lưu trữ các ký tự (chữ số)

    // Bảng chữ số cho các hệ số lớn hơn 10
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Chuyển đổi số nguyên sang hệ số mong muốn
    while (number > 0) {
        int remainder = number % base; // Lấy phần dư
        char digit = digits[remainder]; // Chuyển phần dư thành chữ số tương ứng
        push(&s, &digit); // Đẩy chữ số vào Stack
        number /= base;
    }

    // In kết quả từ Stack
    printf("Kết quả chuyển đổi: ");
    while (!isEmpty(&s)) {
        char* digit = (char*)pop(&s); // Lấy chữ số từ Stack
        printf("%c", *digit); // In chữ số
        free(digit); // Giải phóng bộ nhớ
    }
    printf("\n");
}

// Hàm chính
int main() {
    int number, base;

    // Nhập số nguyên và hệ số từ người dùng
    printf("Nhập số nguyên: ");
    scanf("%d", &number);
    printf("Nhập hệ số mong muốn (2-36): ");
    scanf("%d", &base);

    // Chuyển đổi và in kết quả
    convertNumber(number, base);

    return 0;
}