#include <stdio.h>

typedef struct Node
{
    int info;
    struct Node *next;
}Node;

typedef struct Circular_Linked_List
{
    Node* last;
}Circular_Linked_List;

void initCLL(Circular_Linked_List* cll)
{
    cll -> last = NULL;
}

void insertBegin(Circular_Linked_List* cll, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> info = data;
    if (cll -> last == NULL)
    {
        cll -> last = newNode;
        cll -> last -> next = newNode;
        return;
    }
    newNode -> next = cll -> last -> next;
    cll -> last -> next = newNode;
}

void dispaly(Circular_Linked_List* cll){
    if (cll -> last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node* pt = cll -> last -> next;
    while (pt  != cll -> last)
    {
        printf("%d ", pt -> info);
        pt = pt -> next;
    }
    printf("%d\n", cll -> last -> info);
}

int main()
{
    Circular_Linked_List cll;
    initCLL(&cll);
    insertBegin(&cll, 11);
    insertBegin(&cll, 22);
    insertBegin(&cll, 33);
    insertBegin(&cll, 44);
    insertBegin(&cll, 55);
    dispaly(&cll);
    return 0;
}

