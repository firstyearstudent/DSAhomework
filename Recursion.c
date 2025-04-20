#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hàm tính tổng các phần tử trong mảng bằng đệ quy
int Sum_of_Array(int A[], int n) {
    if (n <= 0)
        return 0;
    return A[n-1] + Sum_of_Array(A, n-1);
}

// Hàm tìm phần tử nhỏ nhất trong mảng bằng đệ quy
int Smallest_Finder(int A[], int n) {
    if (n == 1)
        return A[0];
    int min = Smallest_Finder(A, n-1);
    return (A[n-1] < min) ? A[n-1] : min;
}

// Hàm tìm ước chung lớn nhất của hai số bằng đệ quy
int UCLN(int a, int b) {
    if (b == 0)
        return a;
    return UCLN(b, a % b);
}

// Hàm tính tổng các số dương trong mảng bằng đệ quy
int Sum_of_Positive(int A[], int n) {
    if (n <= 0)
        return 0;
    int sum = Sum_of_Positive(A, n-1);
    if (A[n-1] > 0)
        sum += A[n-1];
    return sum;
}

/* Hàm đảo ngược chuỗi sử dụng vòng lặp
void Reverse_Message(char c[]) {
    int left = 0;                // Chỉ số bắt đầu (đầu chuỗi)
    int right = strlen(c) - 1;   // Chỉ số kết thúc (cuối chuỗi)

    // Lặp qua chuỗi và hoán đổi các ký tự
    while (left < right) {
        // Hoán đổi ký tự tại vị trí left và right
        char temp = c[left];
        c[left] = c[right];
        c[right] = temp;

        // Di chuyển chỉ số left sang phải và right sang trái
        left++;
        right--;
    }
}*/

// Hàm đảo ngược chuỗi bằng đệ quy
void Reverse_Message(char c[], int left, int right) {
    if (left >= right)
        return;
    char temp = c[left];
    c[left] = c[right];
    c[right] = temp;
    Reverse_Message(c, left + 1, right - 1);
}

// Hàm tính tổ hợp chập k của n bằng đệ quy
int ToHop(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return ToHop(n-1, k-1) + ToHop(n-1, k);
}

int main() {
    int n;
    scanf("%d", &n);
    int Array[10000];
    for(int i = 0; i < n; i++){
        scanf("%d", &Array[i]);
    }
    int a, b;
    scanf("%d %d", &a, &b);
    char C[10000];
    getchar(); // Đọc ký tự newline còn lại sau scanf
    fgets(C, 10000, stdin);

    // Tính tổng các phần tử trong mảng
    printf("Sum of Array: %d\n", Sum_of_Array(Array, n));

    // Tìm phần tử nhỏ nhất trong mảng
    printf("Smallest Element: %d\n", Smallest_Finder(Array, n));

    // Tìm ước chung lớn nhất của a và b
    printf("UCLN of %d and %d: %d\n", a, b, UCLN(a, b));

    // Tính tổng các số dương trong mảng
    printf("Sum of Positive Elements: %d\n", Sum_of_Positive(Array, n));

    // Đảo ngược chuỗi
    Reverse_Message(C, 0, strlen(C) - 1);
    printf("Reversed Message: %s", C);

    // Tính tổ hợp chập b của a
    printf("ToHop(%d, %d): %d\n", a, b, ToHop(a, b));

    return 0;
}