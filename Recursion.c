#include <stdio.h>
#include <string.h>

// Hàm tính tổng bình phương từ 1 đến N bằng đệ quy
int sumOfSquares(int n) {
    if (n <= 0) return 0;
    return n * n + sumOfSquares(n - 1);
}

// Hàm tính a mũ b bằng đệ quy
int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
}

// Hàm đếm số chữ số của một số nguyên dương bằng đệ quy
int countDigits(int n) {
    if (n < 10) return 1;
    return 1 + countDigits(n / 10);
}

// Hàm kiểm tra chuỗi đối xứng bằng đệ quy
int isPalindrome(char str[], int start, int end) {
    // Trường hợp cơ sở: nếu chỉ còn 1 ký tự hoặc không còn ký tự nào
    if (start >= end) return 1;
    
    // Nếu hai ký tự ở hai đầu không giống nhau
    if (str[start] != str[end]) return 0;
    
    // Gọi đệ quy với đoạn chuỗi bên trong
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    int choice, n, a, b;
    char str[100];
    
    do {
        printf("\nMenu:\n");
        printf("1. Tinh tong binh phuong tu 1 den N\n");
        printf("2. Tinh a mu b\n");
        printf("3. Dem so chu so cua mot so nguyen duong\n");
        printf("4. Kiem tra chuoi doi xung\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Nhap N: ");
                scanf("%d", &n);
                printf("Tong binh phuong tu 1 den %d la: %d\n", n, sumOfSquares(n));
                break;
                
            case 2:
                printf("Nhap a: ");
                scanf("%d", &a);
                printf("Nhap b: ");
                scanf("%d", &b);
                printf("%d mu %d = %d\n", a, b, power(a, b));
                break;
                
            case 3:
                printf("Nhap so nguyen duong: ");
                scanf("%d", &n);
                if (n > 0)
                    printf("So chu so cua %d la: %d\n", n, countDigits(n));
                else
                    printf("Vui long nhap so nguyen duong!\n");
                break;
                
            case 4:
                printf("Nhap chuoi: ");
                scanf(" %[^\n]s", str); // Đọc cả chuỗi kể cả khoảng trắng
                if (isPalindrome(str, 0, strlen(str) - 1))
                    printf("Chuoi '%s' la chuoi doi xung\n", str);
                else
                    printf("Chuoi '%s' khong phai chuoi doi xung\n", str);
                break;
                
            case 0:
                printf("Tam biet!\n");
                break;
                
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
    
    return 0;
}