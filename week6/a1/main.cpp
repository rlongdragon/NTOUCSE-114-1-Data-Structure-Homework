#include <stdlib.h>

#include <iostream>

using namespace std;

int main() {
  string str;
  cin >> str;

  int maxCount = 0;
  int index = 0;

  for (int i = 0; i < str.length(); i++) {
    int count = 1;
    for (; str[i - count] == str[i + count]; count++);
    count--;
    if (maxCount < count) {
      maxCount = count;
      index = i;
    }
  }

  for (int i = index - maxCount; i < index; i++) {
    printf("%c", str[i]);
  }
  printf("%c", str[index]);
  for (int i = index + 1; i <= index + maxCount; i++) {
    printf("%c", str[i]);
  }
  printf("\n");

  return 0;
}