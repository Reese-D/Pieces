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
  char checkHelper(int index, int direction){
    try{
      return board.at(index + direction);
    }catch(std::out_of_range o){
      std::cout<<o.what()<<std::endl;
    }
  }
  char Player::checkAbove(int index){
    checkHelper(index, ABOVE);
  };
  char Player::checkBelow(int index){
    checkHelper(index, BELOW);
  }
  char Player::checkLeft(int index){
    checkHelper(index, LEFT);
  }
  char Player::checkRight(int index){
    checkHelper(index, RIGHT);
  }
  void Player::scoreBoard(){}
  std::vector<int> Player::checkValidMove(){}

int main(){
  return 0;
}
