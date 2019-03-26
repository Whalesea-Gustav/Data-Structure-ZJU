#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct PolyNode *Polynomial;
struct PolyNode {
    int coef;
    int expon;
    Polynomial link;
};

Polynomial ReadPolynomial() {
    bool Attach(int co, int ex, Polynomial* poly);
    Polynomial start, tmp;
    start = (Polynomial) malloc(sizeof(struct PolyNode));
    tmp = start;
    int N, coef, expon;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &coef, &expon);
        Attach(coef, expon, &tmp);
    }

    return start->link;
}

bool Attach(int co, int ex, Polynomial* poly) {
    Polynomial newPoly = (Polynomial) malloc(sizeof(struct PolyNode));
    newPoly->coef = co;
    newPoly->expon = ex;
    (*poly)->link = newPoly;
    *poly = newPoly; //修改poly指针内的内容
}

int main() {
    Polynomial ReadPolynomial();
    Polynomial P1;
    P1 = ReadPolynomial();

}