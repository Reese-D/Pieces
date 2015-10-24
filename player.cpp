/*
initial board structure for the Othello game
*/
//using namespace std;
#include "player.hpp"
#include <iostream>
#define ABOVE -8
#define BELOW 8
#define LEFT -1
#define RIGHT 1

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

int main(){
  return 0;
}
