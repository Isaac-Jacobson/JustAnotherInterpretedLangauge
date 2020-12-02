#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include <vector>
#include "Rule.h"
class Board{
private:
	char alive;
	char dead;
	Rule rule;
	std::vector<std::vector<char>> loadArr(char *filename);
	std::vector<std::vector<char>> nextGen(std::vector<std::vector<char>> parents, int rows, int cols, char alive, char dead, std::vector<int> bVals, std::vector<int> sVals);
	int numNeighbors(std::vector<std::vector<char>> arr, int rows, int cols, int row, int col, char alive);
	int isAlive(std::vector<std::vector<char>> arr, int row, int col, char alive);
	bool contains(std::vector<int> vec, int num);
	bool hasWrap(int rows, int cols, int row, int col);
	int numNeighborsWrap(std::vector<std::vector<char>> arr, int row, int col,int rows,int cols, char alive);
	int numNeighborsNoWrap(std::vector<std::vector<char>> arr, int row, int col, char alive);
	char* convert(std::string text);
public:
	Board(std::string filename, Rule rule, char live, char dead);
	Board(std::string filename, char live, char dead, Rule rule);
	Board(std::string filename, char live, char dead);
	Board(std::string filename, Rule rule);
	Board(std::string filename);
	~Board();
	Board &operator++();
	int getRows();
	int getCols(); 	
	int rows;
	int cols;
        std::vector<std::vector<char>> board;
}; 
std::ostream & operator <<(std::ostream &out, const Board &board);

#endif //_BOARD_H_
