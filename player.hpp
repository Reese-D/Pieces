#include <vector>

using namespace::std;

class Player{

public:
  std::vector<char> board;
  char color;
  int time;
  Player(vector<char> in_board, char color, int time);
  char opposingColor;
  bool checkRightBounds(int index);
  bool checkLeftBounds(int index);
  char checkAboveRight(int index, std::vector<int> *board);
  char checkAboveLeft(int index, std::vector<int> *board);
  char checkBelowLeft(int index, std::vector<int> *board);
  char checkBelowRight(int index, std::vector<int> *board);
  char checkAbove(int index, std::vector<int> *board);
  char checkBelow(int index, std::vector<int> *board);
  char checkLeft(int index, std::vector<int> *board);
  char checkRight(int index, std::vector<int> *board);
  void scoreBoard();
  std::vector<int> checkValidMoves(std::vector<int> *board);
  void movesHelper(int index, std::vector<int> *validMoves, std::vector<int> *board);
private:
  char checkHelper(int index, int direction, std::vector<int> *board);

};
