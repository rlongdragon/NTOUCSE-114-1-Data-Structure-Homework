#include <iostream>

struct term {
  int row;
  int col;
  int value;
};

void transpose(term a[], term b[]) { /* 轉置a之後放進b裡 */
  int n, i, j, currentb;
  n = a[0].value;      /* 所有元素的個數 */
  b[0].row = a[0].col; /* b的列數等於a的行數 */
  b[0].col = a[0].row; /* b的行數等於a的列數 */
  b[0].value = n;
  if (n > 0) { /* 非零矩陣 */
    currentb = 1;
    for (i = 0; i < a[0].col; i++) /* 依照a的行轉置 */
      for (j = 1; j <= n; j++)     /* 從目前的行中找元素 */
        if (a[j].col == i) {
          /* 元素在目前的行裡,把它加入b中 */
          b[currentb].row = a[j].col;
          b[currentb].col = a[j].row;
          b[currentb].value = a[j].value;
          currentb++;
        }
  }
}

void printTerm(term a[]) {
  for (int i = 0; i <= a[0].value; i++) {
    printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
  }
}

int main() {
  term data[1000];
  term transed[1000];

  scanf("%d %d %d", &data[0].row, &data[0].col, &data[0].value);

  // read data input
  for (int i = 1; i <= data[0].value; i++) {
    scanf("%d %d %d", &data[i].row, &data[i].col, &data[i].value);
  }

  transpose(data, transed);

  // printf("\n\n");
  printTerm(transed);

  return 0;
}