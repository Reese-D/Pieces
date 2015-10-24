/*
initial board structure for the Othello game
*/
//using namespace std;
#include "player.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#define ABOVE -8
#define BELOW 8
#define LEFT -1
#define RIGHT 1

using namespace::std;

  Player::Player(vector<char> in_board, char in_color, int in_time)
  {
    board = in_board;

    color = in_color;
    if(in_color == 'w')
      opposingColor = 'b';
    else
      opposingColor = 'w';
    time = in_time;
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
  char Player::checkHelper(int index, int direction, std::vector<char> *board){
    try{
      if(checkLeftBounds(index + direction) && checkRightBounds(index + direction))
        return this->board.at(index + direction);
    }catch(std::out_of_range o){
      std::cout<<o.what()<<std::endl;
    }
    //returns an x if the value is out of bounds
    return 'x';
  }
  char Player::checkAboveRight(int index,std::vector<char> *board){
    if(checkRightBounds(index))
      return checkHelper(index, ABOVE + RIGHT, board);
    return 'x';
  }
  char Player::checkAboveLeft(int index,std::vector<char> *board){
    if(checkLeftBounds(index))
      return checkHelper(index, ABOVE + LEFT, board);
    return 'x';
  }
  char Player::checkBelowLeft(int index,std::vector<char> *board){
    if(checkLeftBounds(index))
      return checkHelper(index, BELOW + LEFT, board);
    return 'x';
  }
  char Player::checkBelowRight(int index,std::vector<char> *board){
    if(checkRightBounds(index))
      return checkHelper(index, BELOW + RIGHT, board);
    return 'x';
  }
  char Player::checkAbove(int index,std::vector<char> *board){
    return checkHelper(index, ABOVE, board);
  };
  char Player::checkBelow(int index,std::vector<char> *board){
    return checkHelper(index, BELOW, board);
  }
  char Player::checkLeft(int index,std::vector<char> *board){
    if(checkLeftBounds(index))
      return checkHelper(index, LEFT, board);
    return 'x';
  }
  char Player::checkRight(int index,std::vector<char> *board){
    if(checkRightBounds(index))
      return checkHelper(index, RIGHT, board);
    return 'x';
  }

  void Player::scoreBoard(std::vector<char> *board){
    int scoreUs = 0;
    int scoreEnemy = 0;
    int score;
    for(int x = 0; x < this->board.size(); x++){
      if(this->board.at(x) == color){
        scoreUs++;
      }else if(this->board.at(x) == opposingColor){
        scoreEnemy++;
      }
    }
    score = scoreUs - scoreEnemy;
    if(scoreEnemy == 0){
      score = 10000;
    }
    if(scoreUs == 0){
      score = -10000;
    }
  }

  /* takes a given board state and provides all possible valid moves
  * ours: a vector of all of the indexes of our pieces on the board
  * enemies: a vector of all the opposing players pieces on the board
  */
  std::vector<int>* Player::checkValidMoves(std::vector<char> *board){
    std::vector<int> *validMoves = new std::vector<int>();
    //look through the board
    for(int x = 0; x < this->board.size(); x++){
      if(this->board.at(x) == color){
        //if we find a piece of ours get all the valid moves around it
        movesHelper(x, validMoves, board);
      }
      //TODO: check for repeats
      //TODO: find the number of stones captured
    }
    return validMoves;

  }

  void Player::movesHelper(int index, std::vector<int> *validMoves, std::vector<char> *board){
    //keep going right until we get a value that isn't an opponents stone
    int listOfDirections [] = {7,-9,-1,-8,8,-7,1,9};
    std::vector<int> directions(listOfDirections, listOfDirections + sizeof(listOfDirections) / sizeof(int) );
    for(int y = 0; y < directions.size(); y++){
      int x = 0; //x is our offset from our piece
      bool flag = false;
      try{
         while(checkHelper(index + x, directions.at(y), board) == opposingColor)
      {
        if((index+x)%8 == 7 && y > 4)
        {
          flag = false;
          break;
        }
        else if((index+x)%8 == 0 && y < 3)
        {
          flag = false;
          break;
        }
        else if(index+x+directions.at(y) > 63 || index+x+directions.at(y) < 0)
        {
          flag = false;
          break;
        }
        x += directions.at(y);
        flag = true;
      }
      }catch(exception e){printf("TEST");fflush(stdout);}
     
      x += directions.at(y);
      //if at least the first space is an opponents stone and the last one is empty
      //then we can make a move
      if(flag){
        validMoves->push_back(index + x);
      }
    }
    for(int i = 0; i < board->size(); i++)
    {
      if(board->at(i) != '-')
      {
        for(int j = 0; j < validMoves->size(); j++)
        {
          if(validMoves->at(j) == i)
          {
            validMoves->at(j) = -1;
          }
        }
      }
    }
  }

  Player::node Player::createTree(std::vector<char> *board){
    checkValidMoves(board);
  }

  std::vector<int> Player::updatedBoard(int index, std::vector<char> *board){
    int listOfDirections [] = {-7,-8,-9,-1,1,7,8,9};
    std::vector<int> directions(listOfDirections, listOfDirections + sizeof(listOfDirections) / sizeof(int) );
    for(int y = 0; y < directions.size(); y++){
      int offset = directions.at(y);
      while(checkHelper(index, offset, board) == opposingColor){
        index +=offset;
      }
    }
  }
int main(int argc, char* argv[]){

  printf("LWLWLWL\n");
  fflush(stdout);
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
  Player* myPlayer = new Player(board, color[0], time);
  printf("%s starting...",color);
  fflush(stdout);
  vector<int>* validMoves = myPlayer->checkValidMoves(&board);
  printf("FINISHED!!!\n");
  fflush(stdout);
  printf("Calculate Random Number...");
  fflush(stdout);
  int randomNumber = rand() % validMoves->size();
  printf("Finsihed!");
  fflush(stdout);
  printf("Valid Moves:\n");
  for(int i = 0; i < validMoves->size(); i++)
  {
    printf("\t%i", validMoves->at(i));
  }
  printf("\n%s move: %i\n", color, validMoves->at(randomNumber));
  fflush(stdout);
  int move = -1;
  while(move < 0 || move > 63)
  {
    move = validMoves->at(randomNumber);
    
    randomNumber++;
    randomNumber = randomNumber%validMoves->size();
    if(move == -1)
    {
      printf("INVALID, trying again...\n");
      printf("Current Size: %lu\n", validMoves->size());
      printf("Next index to try: %i\n", randomNumber);
    }
  }
  delete validMoves;
  delete myPlayer;
  return move;
}
