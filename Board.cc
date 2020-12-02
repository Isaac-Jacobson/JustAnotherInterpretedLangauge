#include "Board.h"
#include <string>
#include "Rule.h"
#include <iostream>
#include <vector> 
#include <fstream>
#include <stdexcept>
using namespace std;

Board::Board(string filename, Rule rule1, char live, char dead1){
    alive = live;
    dead = dead1;
    board = loadArr(convert(filename));
    rule = rule1;
    rows = board.size();
    cols = board[0].size();
}
Board::Board(string filename, char live, char dead1, Rule rule1){
     alive = live;
    dead = dead1;
    board = loadArr(convert(filename));
    rule = rule1;
    rows = board.size();
    cols = board[0].size();

}
Board::Board(string filename, char live, char dead1){
     Rule r;
     alive = live;
    dead = dead1;
    board = loadArr(convert(filename));
    rule = r;
    rows = board.size();
    cols = board[0].size();

}
Board::Board(string filename, Rule rule1){
    alive = 'O';
    dead = '.';
    board = loadArr(convert(filename));
    rule = rule1;
    rows = board.size();
    cols = board[0].size();

}
Board::Board(string filename){
    Rule r;
    alive = 'O';
    dead = '.';
    board = loadArr(convert(filename));
    rule = r;
    rows = board.size();
    cols = board[0].size();

}
Board::~Board(){
    rule.~Rule();
}
char* Board::convert(string text){
    char* out = new char[text.size() + 1];
    std::copy(text.begin(), text.end(), out);
    out[text.size()] = '\0';
    return out;
}

Board& Board::operator++(){
    board = nextGen(board, rows, cols, alive, dead, rule.getBVals(), rule.getSVals());
    return *this;
}
int Board::getRows(){
    return rows;
}
int Board::getCols(){
    return cols;
}
ostream & operator <<(std::ostream &out, const Board &board){ 
    int rows = board.rows;
    int cols = board.cols;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            out << board.board[i][j];
        }
        out << "\n";
    }
    return out;
}
vector<vector<char>> Board::loadArr(char *filename){
    vector<vector<char>> arr;
   ifstream fl;
   fl.open(filename);
   if(!fl.is_open()){
       throw runtime_error("File can't be opened!");
   }
   string input = "";
        while (getline(fl, input)){
                vector<char>  v(input.begin(), input.end());
            arr.push_back(v);
        }
    if(arr.size() < 2 || arr[0].size() < 2){
	throw runtime_error("Board is too small!");
    }
        return arr;
}
vector<vector<char>> Board::nextGen(vector<vector<char>> parents, int rows1, int cols1, char alive1, char dead1, vector<int> bVals, vector<int> sVals){
    vector<vector<char> > children(rows1, vector<char>(cols1));
    int neighbors = 0;
    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols1; j++){
            neighbors = numNeighbors(parents, rows1, cols1, i, j, alive1);
            if(isAlive(parents, i, j, alive1)){
                if(contains(sVals, neighbors)){
                    children[i][j] = alive1;
                }else{
                    children[i][j] = dead1;
                }
            }else{
                if(contains(bVals, neighbors)){
                    children[i][j] = alive1;
                }else{
                    children[i][j] = dead1;
                }
            }
        }
    }
    return children;
}
int Board::numNeighbors(vector<vector<char>> arr, int rows1, int cols1, int row, int col, char alive1){
    if(hasWrap(rows1, cols1, row, col)){
        return numNeighborsWrap(arr,row,col,rows1,cols1, alive1);
    }
    return numNeighborsNoWrap(arr,row,col, alive1);
}
int Board::isAlive(vector<vector<char>> arr, int row, int col, char alive1){
     if(arr[row][col] == alive1){
         return 1;
     }
     return 0;
}
bool Board::contains(vector<int> vec, int num){
    for(int i : vec){
        if(i == num){
            return true;
        }
    }
    return false;
}
bool Board::hasWrap(int rows1, int cols1, int row, int col){
    return(row == 0 || col == 0 || row == rows1-1 || col ==cols1-1);
}
int Board::numNeighborsWrap(vector<vector<char>> arr, int row, int col,int rows1, int cols1, char alive1){
  if(row == 0){
      if(col == 0){
          return isAlive(arr,row,col+1, alive1)+isAlive(arr,row+1,col, alive1)+isAlive(arr,row+1,col+1, alive1)+isAlive(arr,rows1-1,col, alive1)+isAlive(arr,rows1-1,col+1, alive1)+isAlive(arr,row,cols1-1, alive1)+isAlive(arr,row+1,cols1-1, alive1)+isAlive(arr,rows1-1,cols1-1, alive1);
      }else if(col == cols1-1){
            return isAlive(arr,0,0, alive1)+isAlive(arr,row+1,0, alive1)+isAlive(arr,0,col-1, alive1)+isAlive(arr,row+1,col-1, alive1)+isAlive(arr,row+1,col, alive1)+isAlive(arr,rows1-1,0, alive1)+isAlive(arr,rows1-1,col-1, alive1)+isAlive(arr,rows1-1,cols1-1,alive1);
      }
    return isAlive(arr,row,col-1,alive1)+isAlive(arr,row,col+1, alive1)+isAlive(arr,row+1,col-1, alive1)+isAlive(arr,row+1,col, alive1)+isAlive(arr,row+1,col+1,alive1)+isAlive(arr,rows1-1,col-1,alive1)+isAlive(arr,rows1-1,col,alive1)+isAlive(arr,rows1-1,col+1,alive1);
  }else if(row == rows1-1){
      if(col == 0){
          return isAlive(arr,row-1,col,alive1)+isAlive(arr,row-1,col+1,alive1)+isAlive(arr,row,col+1,alive1)+isAlive(arr,row,cols1-1,alive1)+isAlive(arr,row-1,cols1-1,alive1)+isAlive(arr,0,0,alive1)+isAlive(arr,0,col+1,alive1)+isAlive(arr,0,cols1-1,alive1);
      }else if(col == cols1-1){
          return isAlive(arr,row-1,col-1,alive1)+isAlive(arr,row-1,col,alive1)+isAlive(arr,row,col-1,alive1)+isAlive(arr,0,col-1,alive1)+isAlive(arr,0,col,alive1)+isAlive(arr,row-1,0,alive1)+isAlive(arr,row,0,alive1)+isAlive(arr,0,0,alive1);
      }
    return isAlive(arr,row-1,col-1,alive1)+isAlive(arr,row-1,col,alive1)+isAlive(arr,row-1,col+1,alive1)+isAlive(arr,row,col-1,alive1)+isAlive(arr,row,col+1,alive1)+isAlive(arr,0,col-1,alive1)+isAlive(arr,0,col,alive1)+isAlive(arr,0,col+1,alive1);
  }else if(col == 0){
      return isAlive(arr,row-1,col,alive1)+isAlive(arr,row-1, col+1,alive1)+isAlive(arr,row,col+1,alive1)+isAlive(arr,row+1,col,alive1)+isAlive(arr,row+1,col+1,alive1)+isAlive(arr,row-1,cols1-1,alive1)+isAlive(arr,row,cols1-1,alive1)+isAlive(arr,row+1,cols1-1,alive1);
  }else{
      return isAlive(arr,row-1,col-1,alive1)+isAlive(arr,row-1, col,alive1)+isAlive(arr,row,col-1,alive1)+isAlive(arr,row+1,col-1,alive1)+isAlive(arr,row+1,col,alive1)+isAlive(arr,row-1,0,alive1)+isAlive(arr,row,0,alive1)+isAlive(arr,row+1,0,alive1);
  }
}
int Board::numNeighborsNoWrap(vector<vector<char>> arr, int row, int col, char alive1){
    int livingNeighbors = 0;
    for(int i = row-1; i <= row+1; i++){
        for(int j = col-1; j <= col+1; j++){
            livingNeighbors += isAlive(arr, i, j, alive1);
        }
    }
    return livingNeighbors - isAlive(arr, row, col, alive1);
}
    
