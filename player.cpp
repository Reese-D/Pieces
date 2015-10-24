/*
initial board structure for the Othello game
*/
//using namespace std;
#include "player.hpp"
#include <stdlib.h>
#include <iostream>
#define ABOVE -8
#define BELOW 8
#define LEFT -1
#define RIGHT 1

using namespace::std;

  Player::Player(vector<char> in_board, char in_color, int in_time)
  {
    board = in_board;
    color = in_color;
    time = in_time;
    printf("Color: %c\nTime: %i\n", color, time);
  }

  //Declare functions
  bool Player::checkRightBounds(int index){
    if((index + 1) % 8 == 0)
      return false;
    return true;
  }
  bool Player::checkLeftBounds(int index){
    if((index) % 8 == 0)
      return false;
    return true;
  }
  char Player::checkHelper(int index, int direction){
    try{
      return board.at(index + direction);
    }catch(std::out_of_range o){
      std::cout<<o.what()<<std::endl;
    }
    //returns an x if the value is out of bounds
    return 'x';
  }
  char Player::checkAboveRight(int index){
    if(checkRightBounds(index))
      return checkHelper(index, ABOVE + RIGHT);
    return 'x';
  }
  char Player::checkAboveLeft(int index){
    if(checkLeftBounds(index))
      return checkHelper(index, ABOVE + LEFT);
    return 'x';
  }
  char Player::checkBelowLeft(int index){
    if(checkLeftBounds(index))
      return checkHelper(index, BELOW + LEFT);
    return 'x';
  }
  char Player::checkBelowRight(int index){
    if(checkRightBounds(index))
      return checkHelper(index, BELOW + RIGHT);
    return 'x';
  }
  char Player::checkAbove(int index){
    return checkHelper(index, ABOVE);
  };
  char Player::checkBelow(int index){
    return checkHelper(index, BELOW);
  }
  char Player::checkLeft(int index){
    if(checkLeftBounds(index))
      return checkHelper(index, LEFT);
    return 'x';
  }
  char Player::checkRight(int index){
    if(checkRightBounds(index))
      return checkHelper(index, RIGHT);
    return 'x';
  }
  void Player::scoreBoard(){}
  std::vector<int> Player::checkValidMove(){
    //TODO: finish function
    std::vector<int> temp;
    temp.reserve(6);
    return temp;
  }

int main(int argc, char* argv[]){
  
  char* boardJSON = argv[2];
  
  char* boardStates = strtok(boardJSON, "[]");
  
  boardStates = strtok(NULL, "[]");
  
  char* state = strtok(boardStates, ",");
  vector<char> board;
  while(state != NULL)
  {
    char tok = state[1];
    board.push_back(tok);
    state = strtok(NULL,",");
  }
  
  char* color = argv[4];
  int time = atoi(argv[6]);
  Player myPlayer = Player(board, color[0], time);
  return 0;
}
