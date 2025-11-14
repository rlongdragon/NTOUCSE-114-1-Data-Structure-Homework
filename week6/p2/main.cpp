#include <iostream>

#define MAX_STACK_SIZE 100 /*maximum stack size*/

typedef struct {
  short int vert;
  short int horiz;
} offsets;

offsets move[8];

typedef struct {
  short int row;
  short int col;
  short int dir;
} element;

template <class T>
class Stk {
 private:
  int top = 0;
  T list[100];

 public:
  void push(T item) { list[++top] = item; }

  T pop() { return list[top--]; }
};

int offset[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Board {
 private:
  int inputRow = 0;
  short data[10][10];

 public:
  bool isWay(int col, int row) { return !data[row][col]; }
  void writeMap(short rowData[10]) {
    for (int i = 0; i < 10; i++) {
      data[inputRow][i] = rowData[i];
    }
    inputRow++;
  }
  int nextBlock(int col, int row) {
    int result = 0;
    for (int i = 1; i <= 4; i++) {
      result << 1;
      result += isWay(col + offset[i][0], row + offset[i][1]);
    }
    return result;
  }
  void printBoard() {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        // for (int j = 9; j >= 0; j--) {
        std::cout << (data[i][j] ? 1 : 0) << " ";
      }
      std::cout << std::endl;
    }
  }
};

int main() {
  Board board;

  for (int i = 0; i < 10; i++) {
    short temp[10];
    for (int j = 0; j < 10; j++) {
      // for (int j = 9; j >= 0; j--) {
      std::cin >> temp[j];
      board.writeMap(temp);
    }
  }

  board.printBoard();

  // printf("%d %d\n", board.isWay(1, 2), board.isWay(8, 8));
  Stk<element> path;
  while (true) {
    
  }
}