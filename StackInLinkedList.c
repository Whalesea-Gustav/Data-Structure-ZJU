#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ElementType int
#define ERROR -1;
typedef struct SNode {
    ElementType Data;
    struct SNode* Next;
}* PtrToSNode;

typedef PtrToSNode Stack;

Stack CreatStack() {
    Stack S;
    S = (Stack) malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}
bool IsEmpty(Stack S) {
    return S->Next == NULL;
}

bool Push(Stack S, ElementType X) {
    PtrToSNode newSNode;
    newSNode = (PtrToSNode) malloc(sizeof(struct SNode));
    newSNode->Data = S;
    newSNode->Next = S->Next;
    S->Next = newSNode;
    return true;
}

ElementType Pop(Stack S) {
    PtrToSNode FirstCell;
    ElementType TopElement;
    if (IsEmpty(S)) {
        printf("堆栈空\n");
        return ERROR;
    } else {
        FirstCell = S->Next;
        TopElement = FirstCell->Data;
        //S是指针，对S的操作可以永改变S的内容
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElement; 
    }
}
