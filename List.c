#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct LNode *PtrToLNode;
struct LNode {
    int Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position; 
typedef PtrToLNode List;
typedef int ElementType;
#define ERROR NULL

/* 查找 */
Position Find(List L, int X) {
    Position p = L;
    while (p && (p->Data != X)) p = p->Next;
    if (p) return p;
    return ERROR;
}

/* 插入 */
/* 这里P是链表结点指针，在P之前插入新结点 
   找到P之前的节点pre，在pre后插入新的节点*/
bool Insert(List L, int X, Position P) {
    Position tmp, pre;
    for (pre=L; pre&&pre->Next!=P;pre=pre->Next) ;
    if (pre == NULL) {
        printf("插入位置参数设置错误\n");
        return false;
    } else {
        /* new 一个新的节点 */
        tmp = (Position) malloc(sizeof(struct LNode));
        tmp->Data = X;
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    } 
}

bool Delete(List L, Position P) {
    Position pre;
    for (pre=L;pre&&pre->Next!=P;pre=pre->Next) ;
    if (pre == NULL) {
        printf("删除参数错误\n");
    } else {
      pre->Next = P->Next;
      free(P); 
      return true;
    }
}

List Merge(List L1, List L2) {
    List start;
    Position P;
    /* sentinal */
    start = (List) malloc(sizeof(struct LNode));
    start->Data = 100;
    P = start;
    while (L1 != NULL && L2 !=NULL ) {
        if (L1->Data >= L2->Data) {
            P->Next = L2;
            L2 = L2->Next;
            P = P->Next;
        } else {
            P->Next = L1;
            L1 = L1 ->Next;
            P = P->Next;
        }
    }
    if (L1) {
        P->Next = L1;
        L1 = NULL;
    } else {
        P->Next = L2;
        L2 = NULL;
    }
    return start->Next;
}

int main() {
    List L1, L2;
    PtrToLNode E1, E2;
    E1 = (PtrToLNode) malloc(sizeof(struct LNode));
    E2 = (PtrToLNode) malloc(sizeof(struct LNode));
    L1 = (List) malloc(sizeof(struct LNode));
    L2 = (List) malloc(sizeof(struct LNode));
    L1->Next = E1;
    L2->Next = E2;
    L1->Data = 1;
    E1->Data = 3;
    E1->Next =NULL;
    L2->Data = 2;
    E2->Data = 4;
    E2->Next = NULL;
    List result = Merge(L1, L2);
    getchar();

}