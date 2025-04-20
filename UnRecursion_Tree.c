#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Hàm tạo nút mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Hàm giải phóng bộ nhớ cây
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Cấu trúc stack để hỗ trợ duyệt không đệ quy
typedef struct Stack {
    Node** array;
    int capacity;
    int top;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (Node**)malloc(capacity * sizeof(Node*));
    return stack;
}

bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, Node* item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

Node* pop(Stack* stack) {
    if (isEmpty(stack)) return NULL;
    return stack->array[stack->top--];
}

Node* peek(Stack* stack) {
    if (isEmpty(stack)) return NULL;
    return stack->array[stack->top];
}

// 1. Dựng cây nhị phân hoàn chỉnh từ mảng (khử đệ quy)
Node* buildCompleteTreeIterative(int arr[], int size) {
    if (size == 0) return NULL;
    
    Node* root = createNode(arr[0]);
    Node* queue[size];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    for (int i = 1; i < size; ) {
        Node* parent = queue[front++];
        
        // Tạo nút con trái
        if (i < size) {
            parent->left = createNode(arr[i++]);
            queue[rear++] = parent->left;
        }
        
        // Tạo nút con phải
        if (i < size) {
            parent->right = createNode(arr[i++]);
            queue[rear++] = parent->right;
        }
    }
    
    return root;
}

// 2. Duyệt tiền tố (khử đệ quy)
void preOrderIterative(Node* root) {
    if (root == NULL) return;
    
    Stack* stack = createStack(100);
    push(stack, root);
    
    while (!isEmpty(stack)) {
        Node* node = pop(stack);
        printf("%d ", node->data);
        
        if (node->right) push(stack, node->right);
        if (node->left) push(stack, node->left);
    }
    free(stack->array);
    free(stack);
}

// 3. Duyệt trung tố (khử đệ quy)
void inOrderIterative(Node* root) {
    Stack* stack = createStack(100);
    Node* current = root;
    
    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        
        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }
    free(stack->array);
    free(stack);
}

// 4. Duyệt hậu tố (khử đệ quy)
void postOrderIterative(Node* root) {
    if (root == NULL) return;
    
    Stack* stack1 = createStack(100);
    Stack* stack2 = createStack(100);
    push(stack1, root);
    
    while (!isEmpty(stack1)) {
        Node* node = pop(stack1);
        push(stack2, node);
        
        if (node->left) push(stack1, node->left);
        if (node->right) push(stack1, node->right);
    }
    
    while (!isEmpty(stack2)) {
        printf("%d ", pop(stack2)->data);
    }
    
    free(stack1->array);
    free(stack1);
    free(stack2->array);
    free(stack2);
}

// 5. Tính chiều cao cây (khử đệ quy)
int treeHeightIterative(Node* root) {
    if (root == NULL) return 0;
    
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int height = 0;
    
    while (1) {
        int nodeCount = rear - front;
        if (nodeCount == 0) break;
        
        height++;
        
        while (nodeCount > 0) {
            Node* node = queue[front++];
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
            nodeCount--;
        }
    }
    
    return height;
}

// 6. Tính tổng các phần tử (khử đệ quy)
int treeSumIterative(Node* root) {
    if (root == NULL) return 0;
    
    Stack* stack = createStack(100);
    push(stack, root);
    int sum = 0;
    
    while (!isEmpty(stack)) {
        Node* node = pop(stack);
        sum += node->data;
        
        if (node->right) push(stack, node->right);
        if (node->left) push(stack, node->left);
    }
    
    free(stack->array);
    free(stack);
    return sum;
}

// Chương trình chính
int main() {
    printf("PHIEN BAN KHU DE QUY:\n");
    printf("================================\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Dựng cây nhị phân hoàn chỉnh
    Node* root = buildCompleteTreeIterative(arr, size);
    
    // Duyệt cây
    printf("Duyet pre-order: ");
    preOrderIterative(root);
    printf("\n");
    
    printf("Duyet in-order: ");
    inOrderIterative(root);
    printf("\n");
    
    printf("Duyet post-order: ");
    postOrderIterative(root);
    printf("\n");
    
    // Tính chiều cao và tổng các phần tử
    printf("Chieu cao cua cay: %d\n", treeHeightIterative(root));
    printf("Tong cac phan tu tren cay: %d\n", treeSumIterative(root));
    
    // Giải phóng bộ nhớ
    freeTree(root);
    
    return 0;
}