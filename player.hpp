#include <vector>

using namespace::std;

class Player{

public:
  struct node{
  node *parent;
  std::vector<node*> children;
  std::vector<int> boardState;
  int boardScore;
};
  std::vector<char> board;
  char color;
  int time;
  Player(vector<char> in_board, char color, int time);
  char opposingColor;
  bool checkRightBounds(int index);
  bool checkLeftBounds(int index);
  char checkAboveRight(int index, std::vector<char> *board);
  char checkAboveLeft(int index, std::vector<char> *board);
  char checkBelowLeft(int index, std::vector<char> *board);
  char checkBelowRight(int index, std::vector<char> *board);
  char checkAbove(int index, std::vector<char> *board);
  char checkBelow(int index, std::vector<char> *board);
  char checkLeft(int index, std::vector<char> *board);
  char checkRight(int index, std::vector<char> *board);
  void scoreBoard(std::vector<char> *board);
  std::vector<int>* checkValidMoves(std::vector<char> *board);
  std::vector<int> updatedBoard(int index, std::vector<char> *board);
  void movesHelper(int index, std::vector<int> *validMoves, std::vector<char> *board);
private:
  char checkHelper(int index, int direction, std::vector<char> *board);
  node createTree(std::vector<char> *board);

};
