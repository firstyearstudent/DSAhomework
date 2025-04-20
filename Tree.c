#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct QueueNode {
    Node* node;
    struct QueueNode* next;
}QNode;

typedef struct Queue
{
    QNode* front;
    QNode* rear;
}Queue;

void initQueue(Queue* q){
    q->front = NULL;
    q->rear = NULL;
}

void enQueue(Queue* q, Node* _treeNode){
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode -> node = _treeNode;
    newNode -> next = NULL;
    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    q->rear -> next = newNode;
    q->rear = newNode;
}

Node* deQueue(Queue* q){
    if(q->front == NULL){
        return NULL;
    }
    Node* temp = q->front->node;
    if (q->front == q->rear)
    {
        q->front = q->rear = NULL;
        return temp;
    }
    q->front = q->front->next;
    return temp;
}

void buildBinanyTree(Node** root, int arr[], int size){
    Node* newNode = createNode(arr[0]);
    *root = newNode;
    Queue q;
    initQueue(&q);
    enQueue(&q, *root);
    int i = 1;
    while (i < size)
    {
        Node* current = deQueue(&q);
        if (i < size)
        {
            current -> left = createNode(arr[i]);
            i++;
            enQueue(&q, current->left);
        }
        if (i < size)
        {
            current -> right = createNode(arr[i]);
            i++;
            enQueue(&q, current->right);
        }
        
        current -> left = createNode(arr[i]);
        i++;
        enQueue(&q, current->left);

    }
      
}

void displayPreOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    displayPreOrder(root->left);
    displayPreOrder(root->right);
}

// Tính tổng các phần tử trên cây
int sumTree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sumTree(root->left) + sumTree(root->right);
}

// Trả về phần tử có khóa bằng 5 trên cây
Node* findNode(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    Node* leftResult = findNode(root->left, key);
    if (leftResult != NULL) {
        return leftResult;
    }
    return findNode(root->right, key);
}

// Xác định chiều cao của cây
int treeHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* root = NULL;
    buildBinanyTree(&root, arr, 10);

    // Hiển thị cây theo thứ tự trước
    printf("PreOrder Traversal: ");
    displayPreOrder(root);
    printf("\n");

    // Tính tổng các phần tử trên cây
    int totalSum = sumTree(root);
    printf("Sum of all elements in the tree: %d\n", totalSum);

    // Tìm phần tử có khóa bằng 5
    Node* foundNode = findNode(root, 5);
    if (foundNode != NULL) {
        printf("Node with key 5 found: %d\n", foundNode->data);
    } else {
        printf("Node with key 5 not found.\n");
    }

    // Xác định chiều cao của cây
    int height = treeHeight(root);
    printf("Height of the tree: %d\n", height);

    return 0;
}
