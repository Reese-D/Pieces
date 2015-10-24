#include <vector>

class Player{

public:
  std::vector<char> board;
  char color;
  Player(){
    board.reserve(64);
  }
  bool checkRightBounds(int index);
  bool checkLeftBounds(int index);
  char checkAboveRight(int index);
  char checkAboveLeft(int index);
  char checkBelowLeft(int index);
  char checkBelowRight(int index);
  char checkAbove(int index);
  char checkBelow(int index);
  char checkLeft(int index);
  char checkRight(int index);
  void scoreBoard();
  std::vector<int> checkValidMove();
private:
  char checkHelper(int index, int direction);
};
