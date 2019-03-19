#include<stdio.h>
#include<stdlib.h>

#define MAX 110000
int Next[MAX];
int Data[MAX];

void Reverse(int a[], int start, int end) {
    int len = end - start + 1;

    for (int i = start; i < start + len / 2; i++) {
        int tmp = a[i];
        a[i] = a[start + end - i];
        a[start + end - i] = tmp;
    }
}
void PrintLinkedList(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        printf("%05d %d %05d", a[i], Data[a[i]], a[i+1]);
        putchar('\n');
    }
    printf("%05d %d -1", a[n-1], Data[a[n-1]]);
}
int main() {
    int initAddress, N, K;
    int address, datum, next;
    scanf("%d %d %d", &initAddress, &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &address, &datum, &next);
        Data[address] = datum;
        Next[address] = next;
    }
    int ct = 0;
    int tmp = initAddress;
    int Ordered[N];

    //链表调整至正常顺序
    do {
        Ordered[ct] = tmp;
        tmp = Next[tmp];
        ct++;
    }
    while (tmp != -1);
    //ct = 链表"有效"节点数量

    for (int i = 0; i + K - 1 <= ct - 1; i+=K) {
        Reverse(Ordered, i, i+K-1);
    }
    PrintLinkedList(Ordered, ct);
}