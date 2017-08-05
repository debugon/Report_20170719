#ifndef REVERSIH
#define REVERSIH

#define	SERVER_PORT 55555

#include<iostream>
#include<vector>
#include<WinSock2.h>

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
