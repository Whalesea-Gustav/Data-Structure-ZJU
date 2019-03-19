#include <stdio.h>
#define MAXL 100000

int main() {
    int MaxSubseqSum1(int a[], int len);
    int MaxSubseqSum2(int a[], int start, int end);
    int MaxSubseqSum3(int a[],int len);
    int a[MAXL];
    int len;
    scanf("%d", &len);
    getchar();
    for (int i = 0; i < len; i++) {
        scanf("%d", &a[i]);
    }
    // test for input
    //for (int i = 0; i< len; i++) {
    //   printf("%d", a[i]);
    //  putchar('\n');
    //}
    printf("%d", MaxSubseqSum1(a, len));
    putchar('\n');
    printf("%d", MaxSubseqSum2(a, 0, len-1));
    putchar('\n');
    printf("%d", MaxSubseqSum3(a, len));
}
//返回三个数中的最大值
int Max3(int a, int b, int c) {
    return (a > b) ? (a > c) ? a : c : (b > c) ? b : c;
}

//brute force 暴力求解
int MaxSubseqSum1(int a[], int len) {
    int maxSum = 0;
    int thisSum;
    for (int i = 0; i < len; i++) {
        thisSum = 0;
        for (int j = i; j < len; j++) {
            thisSum += a[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return  maxSum;
}

//分治法
int MaxSubseqSum2(int a[], int start, int end) {
    int Max3(int a, int b, int c);
    if (start == end) {
        return a[start] >= 0 ? a[start] : 0;
    }
    //else if (start - end == 1) {
    //    return Max3(a[start] >= 0 ? a[start]: 0, a[end] >= 0 ? a[end] : 0,
    //    (a[start] + a[end]) >= 0 ? (a[start] + a[end]) : 0);
    //} 这部分好像可以不用加，终止条件直接是start==end
    int middle = (start + end) / 2;
    int left =  MaxSubseqSum2(a, start, middle);
    int right = MaxSubseqSum2(a, middle+1, end);
    int overSum = 0;
    int thisSum = 0;

    //复杂度为N的找出穿越边界的最大子序列和
    for (int i = middle; i >= start; i--) {
        thisSum += a[i];
        if (thisSum > overSum) {
            overSum = thisSum;
        }
    }

    thisSum = overSum;
    for (int i = middle + 1; i <= end; i++) {
        thisSum += a[i];
        if (thisSum > overSum) {
            overSum = thisSum;
        }
    }

    return Max3(left, right, overSum);
}


//在线处理
int MaxSubseqSum3(int a[], int len) {
   int thisSum = 0;
   int maxSum = 0;
   for (int i = 0; i < len; i++) {
       if (thisSum < 0) thisSum = 0;
       thisSum += a[i];
       if (thisSum > maxSum) maxSum = thisSum;
   }
   return maxSum;
}
