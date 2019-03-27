#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define ElementType int
#define ERROR -1;

typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType Data;
    struct SNode *Next;
};

typedef PtrToSNode Stack;

Stack CreatStack() {

    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}
bool IsEmpty(Stack S)
{
    return S->Next == NULL;
}

bool Push(Stack S, ElementType X)
{
    PtrToSNode newSNode;
    newSNode = (PtrToSNode)malloc(sizeof(struct SNode));
    newSNode->Data = X;
    newSNode->Next = S->Next;
    S->Next = newSNode;
    return true;
}

ElementType Pop(Stack S)
{
    PtrToSNode FirstCell;
    ElementType TopElement;
    if (IsEmpty(S))
    {
        printf("堆栈空\n");
        return ERROR;
    }
    else
    {
        FirstCell = S->Next;
        TopElement = FirstCell->Data;
        //S是指针，对S的操作可以永改变S的内容
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElement;
    }
}
ElementType Top(Stack S) {
    return S->Next->Data;
}

int main() {
    int M, N, K; // M stack Maximun | N length of input | K number of checked line
    scanf("%d %d %d", &M, &N, &K);
    
    int inputs[1000];
    for (int i = 0; i < K; i++) {

        //读入数据
        for (int j = 1; j <= N; j++) {
            scanf("%d", &inputs[j]);
        }
        Stack stackM = CreatStack();

        int ct = 1;
        int size = 0;
        for (int l = 1; l <= N; l++) {
            Push(stackM, l);
            size++;
            if (size > M)
                break;

            while (!IsEmpty(stackM) && Top(stackM)==inputs[ct]) {
                Pop(stackM);
                size--;
                ct++;
            }
            
        }
        
        if (IsEmpty(stackM)) printf("YES\n");
        else printf("NO\n");

    }

}
