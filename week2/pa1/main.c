#include <stdio.h>

long fib(int n) {
  if (n <= 1) return n;

  long a[2] = {1, 1};
  for (int i = 1; i < n; i++) {
    long temp = a[0];
    a[0] = a[0] + a[1];
    a[1] = temp;
  }

  return a[1];
}

int main() {
  int n;
  scanf("%d", &n);

  printf("%ld", fib(n));

  return 0;
}