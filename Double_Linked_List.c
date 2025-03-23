#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int info;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct Double_Linked_List
{
    Node* l;
    Node* r;
}Double_Linked_List;



void initDoubleLL(Double_Linked_List* dl){
    dl->l = NULL;
    dl->r = NULL;
}

int isEmpty(Double_Linked_List* dl){
    return (dl->l == NULL);
}

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> info = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    
    return newNode;
}

void insertBegin(Double_Linked_List* dl, int data){
    Node* newNode = createNode(data);
    if(isEmpty(dl)){
        dl->l = dl->r = newNode;
        return;
    }
    
    newNode -> next = dl -> l;
    dl -> l -> prev = newNode;
    dl -> l = newNode;
}

void insertAfter(Double_Linked_List* dl, int data, Node* p){
    Node* newNode = createNode(data);

    if (isEmpty(dl))
    {
        return;
    }

    if (p == NULL)
    {
        return;
    }

    if (p == dl -> r)
    {
        p -> next = newNode;
        newNode -> prev = p;
        dl -> r = newNode;
        return;
    }
    
    newNode -> next = p -> next;
    newNode -> prev = p;
    newNode -> next -> prev = newNode;
    p -> next = newNode;
}

void deleteBegin(Double_Linked_List* dl){
    if(isEmpty(dl)){
        return;
    }
    if(!isEmpty(dl) && dl -> l == dl -> r){
        free(dl -> l);
        dl -> l = dl -> r = NULL;
        return;
    }
    Node* temp = dl -> l;
    dl -> l = temp -> next;
    dl -> l -> prev = NULL;
    free(temp);
}

Node* search(Double_Linked_List* dl, int data){
    if (isEmpty(dl))
    {
        return NULL;
    }
    Node* pt = dl -> l;
    while (pt != NULL && pt -> info != data)
    {
        pt = pt -> next;
    }
    return pt;
}

void insertBefore(Double_Linked_List* dl, int data, Node* p){
    Node* newNode = createNode(data);

    if (isEmpty(dl))
    {
        return;
    }

    if (p == NULL)
    {
        return;
    }
    if (p == dl -> l)
    {
        newNode -> next = dl -> l;
        dl -> l -> prev = newNode;
        dl -> l = newNode;
        exit(1);
    }
    
    newNode -> next = p;
    newNode -> prev = p -> prev;
    //p -> prev = newNode;
    //newNode -> prev -> next = newNode;
    p -> prev -> next = newNode;
    p -> prev = newNode;
}

void deleteCurrentNode(Double_Linked_List* dl, Node* p){
    if (isEmpty(dl))
    {
        return;
    }
    if (p == NULL)
    {
        return;
    }
    if (!isEmpty(dl) &&  dl -> l == dl -> r)
    {
        free(dl -> l);
        dl -> l = dl -> r = NULL;
        return;
    }
    if (p == dl -> l)
    {
        dl -> l = dl -> l -> next;
        dl -> l -> prev = NULL;
        free(p);
        return;
    }
    
    p -> prev -> next = p -> next;
    p -> next -> prev = p -> prev;
    free(p);
}

void display(Double_Linked_List* dl){
    if(isEmpty(dl)){
        printf("Empty list!!");
        exit(1);
    }

    Node*  pt = dl -> l;
    while (pt != NULL)
    {
        printf("%d ", pt -> info);
        pt = pt -> next;
    }
    printf("\n");
}

void freeList(Double_Linked_List* dl) {
    Node* current = dl->l;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    dl->l = dl->r = NULL; // Đặt về NULL sau khi giải phóng
}

int main()
{
    Double_Linked_List dl;
    initDoubleLL(&dl);
    insertBegin(&dl, 11);
    insertBegin(&dl, 22);
    insertBegin(&dl, 33);
    insertBegin(&dl, 44);
    insertBegin(&dl, 55);
    display(&dl);
    Node* temp = search(&dl, 22);
    //insertAfter(&dl, 66, temp);
    insertBefore(&dl, 66, temp);
    display(&dl);
    Node* temp2 = search(&dl, 11);
    insertAfter(&dl, 77, temp2);
    display(&dl);
    deleteBegin(&dl);
    display(&dl);
    deleteCurrentNode(&dl, search(&dl, 55));
    display(&dl);
    freeList(&dl);
    return 0;
}