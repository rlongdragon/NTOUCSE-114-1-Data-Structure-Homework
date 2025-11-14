#include <stdlib.h>

#include <iostream>

using namespace std;

int trainLength;

template <class T>
class Stk {
 private:
  T list[100];

 public:
  int m_top = 0;
  void push(T item) { list[++m_top] = item; }

  T pop() {
    if (m_top > 0) {
      return list[m_top--];
    } else {
      throw std::out_of_range("Stack is empty");
    }
  }

  T top() { return list[m_top]; }

  void print() {
    for (int i = 1; i <= m_top; i++) {
      cout << list[i] << " ";
    }
    printf("\n");
  }
};

void printList(int* list, int length) {
  for (int i = 0; i < length; i++) {
    printf("%d", list[i]);

    if (i == length - 1)
      printf("\n");
    else
      printf(" ");
  }
}

void split(string str, int* list) {
  string temp = "";
  int index = 0;
  for (int i = 0; i < str.length(); i++) {
    char current = str[i];
    if (current == ' ') {
      list[index++] = stoi(temp);
      temp = "";
    } else {
      temp += current;
    }
  }
  list[index++] = stoi(temp);
}

bool verify(int* list) {
  Stk<int> stk;
  int index = 0;
  for (int i = 1; i <= trainLength || stk.top() == list[index]; i++) {
    // printf("DEBUG: list=%d i=%d top=%d\n", list[index], i, stk.top());
    // stk.print();
    if (i == list[index]) {
      index++;
    } else if (stk.top() == list[index]) {
      i--;
      index++;
      stk.pop();
    } else {
      stk.push(i);
    }
  }
  
  return (index == trainLength);
}

int main() {
  scanf("%d\n", &trainLength);

  while (true) {
    string str;
    getline(cin, str);

    if (str == "-1") {
      break;
    }

    int train[trainLength];
    split(str, train);

    cout << (verify(train) ? "YES" : "NO") << endl;
  }

  return 0;
}