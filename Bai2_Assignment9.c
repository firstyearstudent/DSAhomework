#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StringNode {
    char *str;
    int length;
    struct StringNode *left, *right;
} StringNode;

StringNode* createStringNode(const char *str) {
    StringNode *newNode = (StringNode*)malloc(sizeof(StringNode));
    newNode->str = strdup(str);
    newNode->length = strlen(str);
    newNode->left = newNode->right = NULL;
    return newNode;
}

StringNode* insertString(StringNode *root, const char *str) {
    int len = strlen(str);
    if (root == NULL) {
        return createStringNode(str);
    }
    if (len < root->length) {
        root->left = insertString(root->left, str);
    } else {
        root->right = insertString(root->right, str);
    }
    return root;
}

StringNode* minValueStringNode(StringNode *node) {
    StringNode *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

StringNode* deleteString(StringNode *root, const char *str) {
    if (root == NULL) return root;

    int len = strlen(str);
    if (len < root->length) {
        root->left = deleteString(root->left, str);
    } else if (len > root->length) {
        root->right = deleteString(root->right, str);
    } else {
        if (strcmp(root->str, str) == 0) {
            if (root->left == NULL) {
                StringNode *temp = root->right;
                free(root->str);
                free(root);
                return temp;
            } else if (root->right == NULL) {
                StringNode *temp = root->left;
                free(root->str);
                free(root);
                return temp;
            }
            StringNode *temp = minValueStringNode(root->right);
            free(root->str);
            root->str = strdup(temp->str);
            root->length = temp->length;
            root->right = deleteString(root->right, temp->str);
        } else {
            root->right = deleteString(root->right, str);
        }
    }
    return root;
}

void searchByLengthHelper(StringNode *root, int targetLen) {
    if (root == NULL) return;
    if (root->length == targetLen) {
        printf("%s ", root->str);
        searchByLengthHelper(root->right, targetLen);
    } else if (targetLen < root->length) {
        searchByLengthHelper(root->left, targetLen);
    } else {
        searchByLengthHelper(root->right, targetLen);
    }
}

void searchByLength(StringNode *root, int targetLen) {
    searchByLengthHelper(root, targetLen);
    printf("\n");
}

void displayStrings(StringNode *root) {
    if (root != NULL) {
        displayStrings(root->left);
        printf("%s (length: %d)\n", root->str, root->length);
        displayStrings(root->right);
    }
}

int main() {
    StringNode *root = NULL;
    int choice, targetLen;
    char str[100];

    while (1) {
        printf("\n1. Insert string\n2. Delete string\n3. Search by length\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter string to insert: ");
                fgets(str, 100, stdin);
                str[strcspn(str, "\n")] = '\0';
                root = insertString(root, str);
                break;
            case 2:
                printf("Enter string to delete: ");
                fgets(str, 100, stdin);
                str[strcspn(str, "\n")] = '\0';
                root = deleteString(root, str);
                break;
            case 3:
                printf("Enter target length: ");
                scanf("%d", &targetLen);
                getchar();
                printf("Strings with length %d: ", targetLen);
                searchByLength(root, targetLen);
                break;
            case 4:
                printf("Strings in tree:\n");
                displayStrings(root);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}