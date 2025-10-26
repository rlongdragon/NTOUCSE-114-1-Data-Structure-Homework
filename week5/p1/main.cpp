#include <stdio.h>
#include <stdlib.h>

#include <iostream>

struct term {
  int row;
  int col;
  int value;
};

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

void printTerm(term a[]) {
  for (int i = 0; i < a[0].value; i++) {
    printf("%d %d %d\n", a[i + 1].row, a[i + 1].col, a[i + 1].value);
  }
}

void printList(int* list, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d", list[i]);

    if (i == length - 1)
      printf("\n");
    else
      printf(" ");
  };
}

int compare(const void* a, const void* b) {
  const term* termA = (const term*)a;
  const term* termB = (const term*)b;

  if (termA->row > termB->row) {
    return 1;
  } else if (termA->row < termB->row) {
    return -1;
  } else if (termA->col > termB->col) {
    return 1;
  } else if (termA->col < termB->col) {
    return -1;
  } else {
    return 0;
  }
}

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

void multip(term a[], term b[], term result[]) {
  // 0. init result
  result[0].row = a[0].row;
  result[0].col = b[0].row;
  result[0].value = 0;

  int a_rowOffset = 1;

  while (a_rowOffset <= a[0].value) {
    // 1. 選擇一個 A 的 row
    int a_currentRow = a[a_rowOffset].row;
    int a_currentValues[a[0].row] = {0};

    while (true) {
      if (a[a_rowOffset].row == a_currentRow) {
        a_currentValues[a[a_rowOffset].col - 1] = a[a_rowOffset].value;
        a_rowOffset++;
      } else {
        break;
      }
    }

    // 2. 選擇一個 B 的 row
    int b_rowOffset = 1;
    while (b_rowOffset <= b[0].value) {
      int b_currentRow = b[b_rowOffset].row;
      int b_currentValues[b[0].row] = {0};

      // printf("DEBUG: a_row: %d, b_row: %d\n", a_currentRow, b_currentRow);

      while (true) {
        if (b[b_rowOffset].row == b_currentRow) {
          b_currentValues[b[b_rowOffset].col - 1] = b[b_rowOffset].value;
          b_rowOffset++;
        } else {
          break;
        }
      }

      // printf("DEBUG:");
      // printList(a_currentValues, a[0].row + 1);
      // printf("DEBUG:");
      // printList(b_currentValues, b[0].row + 1);

      // 3.計算總和
      int sum = 0;
      for (int i = 0; i < b[0].row; i++) {
        sum += a_currentValues[i] * b_currentValues[i];
      }

      // 4. 如果不為 0 記錄到 result
      if (sum != 0) {
        result[0].value++;
        result[result[0].value].row = a_currentRow;
        result[result[0].value].col = b_currentRow;
        result[result[0].value].value = sum;
      }
    }
  }
}

int main() {
  // your code goes here
  int n;
  term A[10001];
  int w = 0;

  scanf("%d\n", &n);

  for (int i = 0; i < n - 1; i++) {
    scanf("(%d:%d)=%d\n", &(A[i + 1].row), &(A[i + 1].col), &(A[i + 1].value));
    w = max(w, max(A[i + 1].row, A[i + 1].col));
  }
  scanf("(%d:%d)=%d", &(A[n].row), &(A[n].col), &(A[n].value));

  A[0].row = w;
  A[0].col = w;
  A[0].value = n;

  qsort(&A[1], n, sizeof(term), compare);

  // printf("DEBUG:");
  // printTerm(A);
  // term At[10001];
  // transpose(A, At);
  term multiped[10001];
  // multip(A, At, multiped);
  multip(A, A, multiped);

  printTerm(multiped);

  return 0;
}