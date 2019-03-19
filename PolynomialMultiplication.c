#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode* Polynomial;
struct PolyNode {
    int coef;
    int expon;
    Polynomial link;
};

Polynomial ReadPoly() {
    int Attach(int coef, int expon, Polynomial* Ptr2End);
    Polynomial t;
    int num;
    //读取多项式项数
    scanf("%d", &num); 
    Polynomial sentinal = (Polynomial) malloc(sizeof(struct PolyNode));
    sentinal->coef = 123;
    sentinal->expon = 234;
    sentinal->link = NULL;
    Polynomial Ptr2End;
    Ptr2End = sentinal;
    int n, m;
    for (int i = 0; i < num; i++) {
        //给sentinal逐个加上二项式的项
        scanf("%d %d", &n, &m);
        Attach(n, m, &Ptr2End);
    }
    t = sentinal;
    sentinal = sentinal->link;
    free(t);//释放临时头节点
    return sentinal;
}
int Attach(int coe, int exp, Polynomial* Ptr2End) {
    Polynomial newNode = (Polynomial) malloc(sizeof(struct PolyNode));
    newNode->coef = coe;
    newNode->expon = exp;
    newNode->link = NULL;
    (*Ptr2End)->link = newNode;
    (*Ptr2End) = newNode;
    return 0;
}

Polynomial Add(Polynomial P1, Polynomial P2) {
    Polynomial sentinal = (Polynomial) malloc(sizeof(struct PolyNode));
    sentinal->coef = 124;
    sentinal->expon = 234;
    sentinal->link = NULL;
    Polynomial Ptr2End = sentinal;
    while (P1 != NULL && P2 != NULL) {
        if (P1->expon == P2->expon) {
            if (P1->coef + P2->coef != 0) {
                Attach(P1->coef+P2->coef, P1->expon, &Ptr2End);
            }
            P1 = P1->link;
            P2 = P2->link;
        } else if (P1->expon > P2->expon) {
            Attach(P1->coef, P1->expon, &Ptr2End);
            P1 = P1->link;
        } else {
            Attach(P2->coef, P2->expon, &Ptr2End);
            P2 = P2->link;
        }
    }
    while (P1) {
        Attach(P1->coef, P1->expon, &Ptr2End);
        P1 = P1->link;
    }
    while (P2) {
        Attach(P2->coef, P2->expon, &Ptr2End);
        P2 = P2->link;
    }
    Polynomial t;
    t = sentinal;
    sentinal = sentinal->link;
    free(t);
    return sentinal;

}

Polynomial Mult(Polynomial P1, Polynomial P2) {
    if (P1 == NULL || P2 == NULL) return NULL;
    Polynomial sentinal, tmp, t1, t2, PtrOfSentinal;
    int c, e;
    sentinal = (Polynomial) malloc(sizeof(struct PolyNode));
    sentinal->link = NULL;
    t1 = P1; t2 = P2;
    PtrOfSentinal = sentinal;
    while (t1!=NULL) {
        Attach(t1->coef * t2->coef, t1->expon + t2->expon, &PtrOfSentinal);
        t1 = t1->link;
    }
    t2 = t2->link;
    t1 = P1;

    PtrOfSentinal = sentinal;

    while(t2) {
        t1 = P1;
        PtrOfSentinal = sentinal;
        while (t1) {
            c = t1->coef * t2->coef;
            e = t1->expon + t2->expon;
            //将乘法得出的节点加入到sentinal链表中
            while (PtrOfSentinal->link&&PtrOfSentinal->link->expon > e) {
                PtrOfSentinal = PtrOfSentinal->link;
            }
            if (PtrOfSentinal->link&&PtrOfSentinal->link->expon == e) {
                if (PtrOfSentinal->link->coef + c) {
                PtrOfSentinal->link->coef += c;
                } else {
                tmp = PtrOfSentinal->link;
                PtrOfSentinal->link = tmp->link;
                free(tmp);
                }
            } else {
                tmp = (Polynomial) malloc(sizeof(struct PolyNode));
                tmp->coef = c;
                tmp->expon = e;
                tmp->link = PtrOfSentinal->link;
                PtrOfSentinal->link = tmp;
                PtrOfSentinal = PtrOfSentinal->link;
            }
            t1 = t1->link;
        }
        t2 = t2->link;
    }

    tmp = sentinal;
    sentinal = sentinal->link;
    free(tmp);
    return sentinal;
}
int PrintPoly(Polynomial P) {
    if (P == NULL) {
        printf("0 0");
        return 0;
    } else {
        for (;P != NULL; P=P->link) {
            if (P->link == NULL) {
                printf("%d %d", P->coef, P->expon);
            } else {
                printf("%d %d ", P->coef, P->expon);
            }
        }
        return 0;
    }
}
int main() {
    //程序搭建 
    /*1.读入多项式1
      2.读入多项式2
      3.加法计算并输出
      4.乘法计算并输出
      */
    Polynomial P1, P2, PP, PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PS = Add(P1, P2);
    PP = Mult(P1, P2);
    PrintPoly(PP);
    putchar('\n');
    PrintPoly(PS);
    return 0;
}
