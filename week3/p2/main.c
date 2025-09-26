#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int main() {
  int n;
  scanf("%d", &n);

  int list[100001];
  int pre[100001];
  int suf[100001];

  for (int i = 0; i < n; i++) {
    scanf("%d", list + i);
  }

  pre[0] = list[0];
  for (int i = 1; i < n; i++) {
    pre[i] = max(pre[i - 1], list[i]);
  }

  suf[n - 1] = list[n - 1];
  for (int i = n - 2; i > 0; i--) {
    suf[i] = max(suf[i + 1], list[i]);
  }

  int ans = pre[0] + suf[2];

  for (int i = 2; i < n - 1; i++) {
    ans = max(ans, pre[i - 1] + suf[i + 1]);
  }

  printf("%d\n", ans);
  return 0;
}