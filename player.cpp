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
  char Player::checkHelper(int index, int direction){
    try{
      return board.at(index + direction);
    }catch(std::out_of_range o){
      std::cout<<o.what()<<std::endl;
    }
    //This statement shouldn't ever be reached
    return board.at(0);
  }
  char Player::checkAboveRight(int index){
    return checkHelper(index, ABOVE + RIGHT);
  }
  char Player::checkAboveLeft(int index){
    return checkHelper(index, ABOVE + LEFT);
  }
  char Player::checkBelowLeft(int index){
    return checkHelper(index, BELOW + LEFT);
  }
  char Player::checkBelowRight(int index){
    return checkHelper(index, BELOW + RIGHT);
  }
  char Player::checkAbove(int index){
    return checkHelper(index, ABOVE);
  };
  char Player::checkBelow(int index){
    return checkHelper(index, BELOW);
  }
  char Player::checkLeft(int index){
    return checkHelper(index, LEFT);
  }
  char Player::checkRight(int index){
    return checkHelper(index, RIGHT);
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
