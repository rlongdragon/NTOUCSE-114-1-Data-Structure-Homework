#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string P, Q, R;

  getline(std::cin, P);
  getline(std::cin, Q);
  getline(std::cin, R);

  if (Q.empty()) {
    cout << P << endl;
    return 0;
  }

  size_t pos = 0;
  while ((pos = P.find(Q, pos)) != string::npos) {
    P.replace(pos, Q.length(), R);
    pos += R.length();
  }

  cout << P << endl;

  return 0;
}