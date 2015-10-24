#include <vector>

class Player{

public:
  std::vector<char> board;
  char color;
  Player(){
    board.reserve(64);
  }
  char checkAbove(int index);
  char checkBelow(int index);
  char checkLeft(int index);
  char checkRight(int index);
  void scoreBoard();
  std::vector<int> checkValidMove();
private:
  char checkHelper(int index);
};
