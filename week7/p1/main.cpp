#include <stdlib.h>

#include <iostream>

using namespace std;

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

  // void print() {
  //   for (int i = 1; i <= m_top; i++) {
  //     cout << list[i] << " ";
  //   }
  //   printf("\n");
  // }
};

int getWeight(char c) {
  switch (c) {
    case '(':
      return -1;

    case '+':
    case '-':
      return 5;

    case '*':
    case '/':
      return 9;

    default:
      return 0;
  }
}

string postfix(string str) {
  Stk<char> stk;
  string result = "";
  for (int i = 0; i < str.length(); i++) {
    // stk.print();
    // cout << stk.m_top << endl;
    // cout << result << endl;
    char current = str[i];

    switch (current) {
      case ' ':
        break;

      case '(':
        stk.push('(');
        break;

      case ')':
        for (char temp = stk.top(); temp != '(' && stk.m_top > 0;
             temp = stk.top()) {
          result += stk.pop();
          result += " ";
        }
        stk.pop();
        break;

      case '+':
      case '-':
      case '*':
      case '/':
        while (stk.m_top > 0 && stk.top() != '(' &&
               getWeight(stk.top()) >= getWeight(current)) {
          result += stk.pop();
          result += " ";
        }
        stk.push(current);
        break;

      default:
        result += current;
        result += " ";
    }
  }

  while (stk.m_top) {
    result += stk.pop();
    result += " ";
  }

  result.pop_back();
  return result;
}

int main() {
  int inputs;

  for (scanf("%d\n", &inputs); inputs > 0; inputs--) {
    string str;
    getline(cin, str);
    cout << postfix(str) << endl;
  }
  return 0;
}