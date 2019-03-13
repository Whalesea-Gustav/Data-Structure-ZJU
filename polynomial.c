#include <stdio.h>
#include <time.h> // clock 计数
#include <math.h> // pow 函数
#define MAXN 10
#define MAXK 1e8

clock_t start, stop;

int main() {
  double f1(int n, int a[], double x);
  double f2(int n, int a[], double x);
  int i;
  int a[MAXN];
  for (int i = 0; i < MAXN; i++) {
    a[i] = (double) i / MAXN;
  }
  start = clock();
  for (int i = 0; i < MAXK; i++) {
     f1(MAXN, a, 1.1);
  }
  stop = clock();
  double duration = ((double) (stop - start)) / CLK_TCK;
  printf("CLK_TCK is : %d\n", CLK_TCK);
  printf("tick for function 1 : %f\n", (double) (stop - start));
  printf("duration : %6.2e\n", duration);

  start = clock();
  for (int i = 0; i < MAXK; i++) {
    f2(MAXN, a, 1.1);
  }
  stop = clock();
  duration  = ((double) (stop - start)) / CLK_TCK;
  printf("tick for function 1 : %f\n", (double) (stop - start));
  printf("duration : %6.2e\n", duration);
}

double f1(int n, int a[], double x) { // applied to n项式
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i] * pow(x, n);
  }
  return sum;
}

double f2(int n, int a[], double x) {
  double sum = 0;
  for (int i = n-1; i >= 0; i--) {
    sum =  a[i] + x * sum;
  }
  return sum;
}
