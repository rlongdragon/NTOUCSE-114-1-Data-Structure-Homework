#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

template <class T>
class Stk {
 private:
  T list[100];

 public:
  int m_top = 0;

  void push(T item) {
    if (m_top < 99) {
      list[++m_top] = item;
    }
  }

  T pop() {
    if (m_top > 0) {
      return list[m_top--];
    } else {
      throw std::out_of_range("Stack is empty");
    }
  }

  T top() {
    if (m_top > 0) {
      return list[m_top];
    } else {
      throw std::out_of_range("Stack is empty");
    }
  }

  void print() {
    for (int i = 1; i <= m_top; i++) {
      cout << list[i] << " ";
    }
    printf("\n");
  }
};

bool isOperator(const string& token) {
  return token == "+" || token == "-" || token == "*" || token == "/" ||
         token == "%";
}

int performOperation(int operand1, int operand2, const string& op) {
  if (op == "+") return operand1 + operand2;
  if (op == "-") return operand1 - operand2;
  if (op == "*") return operand1 * operand2;
  if (op == "/") return operand1 / operand2;
  if (op == "%") return operand1 % operand2;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string line;
  getline(cin, line);

  stringstream ss(line);
  string token;

  Stk<int> s;

  while (ss >> token) {
    if (isOperator(token)) {
      int operand2 = s.pop();
      int operand1 = s.pop();

      int result = performOperation(operand1, operand2, token);
      s.push(result);
    } else {
      s.push(stoi(token));
    }
  }

  cout << s.top() << endl;

  return 0;
}