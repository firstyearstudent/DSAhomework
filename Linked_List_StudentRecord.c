#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc SinhVien
typedef struct SinhVien {
    long mssv;
    char hoTen[50];
    char khoa[20];
    struct SinhVien* next;
} SinhVien;

// Hàm thêm sinh viên vào danh sách
void addStudent(SinhVien** head, long mssv, const char* hoTen, const char* khoa) {
    SinhVien* newStudent = (SinhVien*)malloc(sizeof(SinhVien));
    newStudent->mssv = mssv;
    strcpy(newStudent->hoTen, hoTen);
    strcpy(newStudent->khoa, khoa);
    newStudent->next = *head;
    *head = newStudent;
}

// Hàm tìm kiếm sinh viên theo MSSV
SinhVien* searchStudent(SinhVien* head, long mssv) {
    SinhVien* current = head;
    while (current != NULL) {
        if (current->mssv == mssv) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Hàm in danh sách sinh viên
void printStudents(SinhVien* head) {
    SinhVien* current = head;
    while (current != NULL) {
        printf("MSSV: %ld, Ho Ten: %s, Khoa: %s\n", current->mssv, current->hoTen, current->khoa);
        current = current->next;
    }
}

int main() {
    SinhVien* head = NULL;
    int n;
    long mssv;
    char hoTen[50], khoa[20];

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); // Đọc ký tự newline sau scanf

    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("MSSV: ");
        scanf("%ld", &mssv);
        getchar(); // Đọc ký tự newline sau scanf
        printf("Ho Ten: ");
        fgets(hoTen, sizeof(hoTen), stdin);
        hoTen[strcspn(hoTen, "\n")] = '\0'; // Xóa ký tự newline
        printf("Khoa: ");
        fgets(khoa, sizeof(khoa), stdin);
        khoa[strcspn(khoa, "\n")] = '\0'; // Xóa ký tự newline

        addStudent(&head, mssv, hoTen, khoa);
    }

    printf("\nDanh sach sinh vien:\n");
    printStudents(head);

    printf("\nNhap MSSV can tim kiem: ");
    scanf("%ld", &mssv);
    SinhVien* foundStudent = searchStudent(head, mssv);
    if (foundStudent != NULL) {
        printf("Tim thay sinh vien co MSSV %ld: %s, Khoa: %s\n", foundStudent->mssv, foundStudent->hoTen, foundStudent->khoa);
    } else {
        printf("Khong tim thay sinh vien co MSSV %ld\n", mssv);
    }

    return 0;
}