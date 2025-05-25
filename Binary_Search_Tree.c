#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

Node* searchNode(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->data == value) {
        return root;
    }
    else if (value < root->data) {
        return searchNode(root->left, value);
    }
    else {
        return searchNode(root->right, value);
    }
}

Node* deleteNode(Node* root, int value) {
    Node* p = root;
    Node* q, *r;
    if (p == NULL) {
        return NULL;
    }
    // The rest of the delete logic should be implemented here
    // For now, just return root to avoid errors
    return root;
}

void display(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    display(root->left);
    display(root->right);
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int A[6] = {11, 33, 9, 44, 18, 7};
    
    // Chèn các nút vào cây
    for(int i = 0; i < 6; i++) {
        root = insertNode(root, A[i]); // Gán lại giá trị root
    }
    
    display(root);
    printf("\n");
    
    // Xóa nút 33
    root = deleteNode(root, 33);
    
    display(root);
    printf("\n");
    
    // Giải phóng bộ nhớ
    freeTree(root);
    
    return 0;
}