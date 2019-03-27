#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

Position BinarySearch(List L, ElementType X) {
    int start = 1, end = L->Last;
    while (start <= end) {
        int middle = (start + end) / 2;
        if (L->Data[middle] > X) {
            end = middle - 1;
        } else if (L->Data[middle] < X) {
            start = middle + 1;
        } else {
            return middle;
        }
        
    }
    return 0;
}

int main() {
    printf("Hello Wolrd\n");
}