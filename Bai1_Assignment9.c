#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút của cây
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// Tạo nút mới
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Thêm phần tử vào cây
Node* insert(Node* root, int key) {
    if (root == NULL) return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    // Nếu key đã tồn tại, không thêm
    return root;
}

// Tìm phần tử nhỏ nhất (dùng cho xóa)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Xóa phần tử khỏi cây
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Nút có 1 hoặc 0 con
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Nút có 2 con
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Tìm kiếm phần tử có khóa là K
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Hiển thị các khóa trên cây (duyệt giữa - in-order)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Tính tổng các khóa
int sumKeys(Node* root) {
    if (root == NULL) return 0;
    return root->key + sumKeys(root->left) + sumKeys(root->right);
}

// Đếm số phần tử của cây
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Giải phóng bộ nhớ cây
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Chương trình chính
int main() {
    Node* root = NULL;
    int choice, key;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Bo sung mot phan tu\n");
        printf("2. Loai bo mot phan tu\n");
        printf("3. Tim kiem phan tu co khoa K\n");
        printf("4. Hien thi cac khoa tren cay (in-order)\n");
        printf("5. Tinh tong cac khoa\n");
        printf("6. Dem so phan tu\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Nhap khoa can them: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Nhap khoa can xoa: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Nhap khoa can tim: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Tim thay %d trong cay.\n", key);
                else
                    printf("Khong tim thay %d trong cay.\n", key);
                break;
            case 4:
                printf("Cac khoa tren cay: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Tong cac khoa: %d\n", sumKeys(root));
                break;
            case 6:
                printf("So phan tu: %d\n", countNodes(root));
                break;
            case 0:
                freeTree(root);
                printf("Da thoat.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
    return 0;
}