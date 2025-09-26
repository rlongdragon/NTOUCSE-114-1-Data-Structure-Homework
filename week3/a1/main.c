#include <stdio.h>

void printRepeat(char c, int n) {
  for (int i = 0; i < n; i++) {
    printf("%c ", c);
  }
}

int main() {
  int total;
  scanf("%d", &total);

  int blocks[1000];
  int len = 0;
  while (scanf("%d", blocks + len) == 1) {
    len++;
  }

  int font[1000] = {0};
  int back[1000] = {0};

  int left = -1;
  for (int i = 0; i < len; i++) {
    left++;
    left += blocks[i];
    font[i] = left;
  }

  int right = total + 3;
  for (int i = len; i >= 0; i--) {
    right--;
    right -= blocks[i];
    back[i] = right;
  }

  int current = 1;
  for (int i = 0; i < len; i++) {
    int from = back[i];
    int to = font[i];

    if (to < from) continue;

    printRepeat('0', from - current);
    printRepeat('1', to - from + 1);

    current = to + 1;
  }
  printRepeat('0', total - current+1);

  printf("\n");

  return 0;
}
