#include <stdio.h>

#define MAX_TERMS 100
typedef struct {
  float coef;
  int expon;
} polynomial;

void pmult(polynomial a[], polynomial b[], polynomial c[], int na, int nb,
           int* nc) {
  int i, j;
  *nc = 0;
  for (i = 0; i < na; i++) {
    for (j = 0; j < nb; j++) {
      c[*nc].coef = a[i].coef * b[j].coef;
      c[(*nc)++].expon = a[i].expon + b[j].expon;
    }
  }
  /* 將c陣列依幂次排列和合併 */
}

void printPoly(polynomial p[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0 && p[i].coef >= 0) printf("+");
    printf("%.2f", p[i].coef);
    if (p[i].expon == 1) {
      printf("x");
    } else if (p[i].expon != 0)
      printf("x^%d", p[i].expon);
  }
  printf("\n");
}

int main() {
  polynomial a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS];
  int na, nb, nc;

  scanf("%d", &na);
  for (int i = 0; i < na; i++) {
    scanf("%f %d", &a[i].coef, &a[i].expon);
  }

  scanf("%d", &nb);
  for (int i = 0; i < nb; i++) {
    scanf("%f %d", &b[i].coef, &b[i].expon);
  }

  for (int i = 0; i < na; i++) {
    if (i > 0 && a[i].coef >= 0) printf("+");
    printf("%.2f", a[i].coef);
    if (a[i].expon == 1) {
      printf("x");
    } else if (a[i].expon != 0)
      printf("x^%d", a[i].expon);
  }
  printf("\n");

  for (int i = 0; i < nb; i++) {
    if (i > 0 && b[i].coef >= 0) printf("+");
    printf("%.2f", b[i].coef);
    if (b[i].expon == 1) {
      printf("x");
    } else if (b[i].expon != 0)
      printf("x^%d", b[i].expon);
  }
  printf("\n");

  pmult(a, b, c, na, nb, &nc);
  printPoly(c, nc);

  return 0;
} 