#include <stdio.h>
#include <stdlib.h>

#define MAXTREE 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode {
    ElementType Data;
    Tree Left;
    Tree Right;
} T1[MAXTREE], T2[MAXTREE];

Tree BuildTree(TreeNode tree[]) {
    int N;
    scanf("%d", &N);
    if (N == 0) return Null;
    int isRoot[N];
    for (int i = 0; i< N; i++) isRoot[i] = 1;

    for (int i = 0; i < N; i++) {
        char data, cl, cr;
        scanf("%c %c %c", &tree[i].Data, &cl, &cr); // 如果有特殊字符出现，需要以char形式导入以判断
        if (cl == '-') {
            tree[i].Left = Null;
        } else {
            tree[i].Left = cl-'0';
            isRoot[tree[i].Left] = 0;
        }
        if (cr == '-') {
            tree[i].Right = Null;
        } else {
            tree[i].Right = cr - '0';
            isRoot[tree[i].Right] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        if (isRoot[i] == 1) return i;
    }
}

int main() {
    printf("hello world\n");
    //Tree Root1 = BuildTree(T1);
    //Tree Root2 = BuildTree(T2);
}
