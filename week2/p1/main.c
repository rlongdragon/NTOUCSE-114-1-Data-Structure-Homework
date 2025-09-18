#define MAX_SIZE 1000
#include <stdio.h>

int list[MAX_SIZE];

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int selectSort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[i]) {
        swap(arr + i, arr + j);
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &list[i]);
  }

  selectSort(list, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", list[i]);
  }
}