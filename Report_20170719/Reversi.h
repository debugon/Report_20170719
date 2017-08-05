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

private:
	const int NUMBER_OF_SQUARE = 8;
	std::vector<std::vector <int> > gameBoard;

};

ReversiEngine::ReversiEngine()
{
}

ReversiEngine::~ReversiEngine()
{
}

#endif // !REVERSIH
