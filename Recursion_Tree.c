#include <stdio.h>
#include <stdlib.h>

// Cấu trúc nút cây nhị phân
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Hàm tạo nút mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 1. Dựng cây nhị phân hoàn chỉnh từ mảng (đệ quy)
Node* buildCompleteTreeRecursive(int arr[], int index, int size) {
    if (index >= size) return NULL;
    
    Node* root = createNode(arr[index]);
    root->left = buildCompleteTreeRecursive(arr, 2*index + 1, size);
    root->right = buildCompleteTreeRecursive(arr, 2*index + 2, size);
    return root;
}

// 2. Duyệt tiền tố (đệ quy)
void preOrderRecursive(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}

// 3. Duyệt trung tố (đệ quy)
void inOrderRecursive(Node* root) {
    if (root == NULL) return;
    inOrderRecursive(root->left);
    printf("%d ", root->data);
    inOrderRecursive(root->right);
}

// 4. Duyệt hậu tố (đệ quy)
void postOrderRecursive(Node* root) {
    if (root == NULL) return;
    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    printf("%d ", root->data);
}

// 5. Tính chiều cao cây (đệ quy)
int treeHeightRecursive(Node* root) {
    if (root == NULL) return 0;
    
    int leftHeight = treeHeightRecursive(root->left);
    int rightHeight = treeHeightRecursive(root->right);
    
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// 6. Tính tổng các phần tử (đệ quy)
int treeSumRecursive(Node* root) {
    if (root == NULL) return 0;
    return root->data + treeSumRecursive(root->left) + treeSumRecursive(root->right);
}

// Giải phóng bộ nhớ cây
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Chương trình chính (phiên bản đệ quy)
void recursiveVersion() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Xay dung cay nhi phan hoan chinh tu mang:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    Node* root = buildCompleteTreeRecursive(arr, 0, size);
    
    printf("Duyet tien to (pre-order): ");
    preOrderRecursive(root);
    printf("\n");
    
    printf("Duyet trung to (in-order): ");
    inOrderRecursive(root);
    printf("\n");
    
    printf("Duyet hau to (post-order): ");
    postOrderRecursive(root);
    printf("\n");
    
    printf("Chieu cao cua cay: %d\n", treeHeightRecursive(root));
    printf("Tong cac phan tu tren cay: %d\n", treeSumRecursive(root));
    
    freeTree(root);
}

// Hàm main
int main() {
    recursiveVersion();
    return 0;
}