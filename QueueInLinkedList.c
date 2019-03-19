#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ElementType int;

typedef struct Node {
    ElementType Data;
    PtrToNode next;
} *PtrToNode;

typedef PtrToNode Position;

typedef struct QNode {
    Position Front, Rear;
    int MaxSize;
} *Queue;

bool IsEmpty(Queue Q) {
    return Q->Front == NULL;
}

ElementType DeleteQ(Queue Q) {
    Position FrontCell;
    ElementType toReturn;
    if (IsEmpty(Q)) {
        printf("队列已空\n");
        return -1;
    } else {
        FrontCell = Q->Front;
        toReturn = FrontCell->Data;
        if (Q->Front == Q->Rear) { //如果队列中仅有一个元素
            Q->Front = Q->Rear = NULL;
        } else {
            Q->Front = FrontCell->next;
        }
        free(FrontCell); //释放被占用空间
        return toReturn;
    }
}
