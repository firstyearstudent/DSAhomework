#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Định nghĩa cấu trúc List
typedef struct {
    float data[MAX_SIZE];
    int size;
} List;

// Khởi tạo List
void initList(List *list) {
    list->size = 0;
}

// Kiểm tra List có đầy không
int isFull(List *list) {
    return list->size == MAX_SIZE;
}

// Kiểm tra List có rỗng không
int isEmpty(List *list) {
    return list->size == 0;
}

// Chèn một phần tử vào List tại vị trí bất kỳ
void insert(List *list, float element, int position) {
    if (isFull(list)) {
        printf("List đầy, không thể chèn thêm phần tử.\n");
        return;
    }
    if (position < 0 || position > list->size) {
        printf("Vị trí không hợp lệ.\n");
        return;
    }
    for (int i = list->size; i > position; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[position] = element;
    list->size++;
}

// Xóa một phần tử khỏi List tại vị trí bất kỳ
float delete(List *list, int position) {
    if (isEmpty(list)) {
        printf("List rỗng, không thể xóa phần tử.\n");
        exit(1);
    }
    if (position < 0 || position >= list->size) {
        printf("Vị trí không hợp lệ.\n");
        exit(1);
    }
    float element = list->data[position];
    for (int i = position; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
    return element;
}

// Lấy một phần tử từ List tại vị trí bất kỳ
float getElement(List *list, int position) {
    if (isEmpty(list)) {
        printf("List rỗng, không có phần tử để lấy.\n");
        exit(1);
    }
    if (position < 0 || position >= list->size) {
        printf("Vị trí không hợp lệ.\n");
        exit(1);
    }
    return list->data[position];
}

int main() {
    List floatList;
    initList(&floatList);

    // Chèn các phần tử vào List
    insert(&floatList, 10.5, 0);
    insert(&floatList, 20.3, 1);
    insert(&floatList, 30.7, 2);

    // Hiển thị các phần tử trong List
    printf("Cac phan tu trong List:\n");
    for (int i = 0; i < floatList.size; i++) {
        printf("%.2f ", getElement(&floatList, i));
    }
    printf("\n");

    // Xóa một phần tử khỏi List
    float deletedElement = delete(&floatList, 1);
    printf("Phan tu da xoa: %.2f\n", deletedElement);

    // Hiển thị lại các phần tử trong List sau khi xóa
    printf("Cac phan tu trong List sau khi xoa:\n");
    for (int i = 0; i < floatList.size; i++) {
        printf("%.2f ", getElement(&floatList, i));
    }
    printf("\n");

    return 0;
}