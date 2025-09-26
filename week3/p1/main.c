#include <stdio.h>

void printList(int* list, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d", list[i]);

    if (i == length - 1)
      printf("\n");
    else
      printf(" ");
  };
}

void insertSort(int* list, int length) {
  int i, key, j;
  for (i = 1; i < length; i++) {
    key = list[i];
    j = i - 1;

    while (j >= 0 && list[j] > key) {
      list[j + 1] = list[j];
      j = j - 1;
    }
    list[j + 1] = key;

    if (i == 1 || i == 2) printList(list, i+1);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int list[10000];
  for (int i = 0; i < n; i++) {
    scanf("%d", list + i);
  }

  insertSort(list, n);

  printList(list, n);
  return 0;
}