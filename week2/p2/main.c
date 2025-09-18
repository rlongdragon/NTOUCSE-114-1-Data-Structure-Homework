#include <stdio.h>

#define MAX_SIZE 1000

int binsearch(int *arr, int size, int target) {
  int left = 0, right = size - 1;

  while (left != right) {
    int mid = (right + left) / 2;

    int result = arr[mid] - target;
    // printf("%d %d %d %d\n", left, mid, right, result);

    if (result > 0) {
      // 當 arr[mid] > target 時執行的程式碼
      right = mid;
    } else if (result < 0) {
      // 當 arr[mid] < target 時執行的程式碼
      left = mid;
    } else {
      // 當 arr[mid] == target 時執行的程式碼
      return mid;
    }
  }
  return -1;
}

int main() {
  int n, k;
  int list[MAX_SIZE];

  scanf("%d%d", &n, &k);

  for (int i = 0; i < k; i++) {
    scanf("%d", &list[i]);
  }

  printf("%d", binsearch(list, k, n));

  return 0;
}