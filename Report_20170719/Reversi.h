#ifndef REVERSIH
#define REVERSIH

#include<iostream>
#include<vector>

#include"SocketConnection.h"

enum StoneFlag { None, Black, White };

class ReversiEngine
{
public:
	ReversiEngine();
	~ReversiEngine();

	void PrintGameBoard();

	StoneFlag GetGameBorard(int x, int y) { return gameBoard[y][x]; };
	void SetGameBoard(int x, int y, StoneFlag flag);

	bool isCheckReverse(int x, int y);

	SystemType GetConnectionType() { return socketConnection.GetSystemType(); }
	void SetConnectionType(SystemType inputType) { socketConnection.SetSystemType(inputType); }

private:
	const int NUMBER_OF_SQUARE = 8;
	std::vector<std::vector <StoneFlag> > gameBoard;

	SocketConnection socketConnection;

};

#endif // !REVERSIH
