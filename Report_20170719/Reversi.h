#ifndef REVERSIH
#define REVERSIH

#define	SERVER_PORT 55555

#include<iostream>
#include<vector>
#include<WinSock2.h>

enum StoneFlag { None, Black, White };
enum SystemType { None, Server, Client };

class ReversiEngine
{
public:
	ReversiEngine();
	~ReversiEngine();

private:
	const int NUMBER_OF_SQUARE = 8;
	std::vector<std::vector <int> > gameBoard;

	SystemType systemType = None;

	WSADATA wsaData;
	int result;

	SOCKET listenSoc, soc;
	SOCKADDR_IN saddr, from;
	int fromlen, rcv;
	char buffer[1000];
	const unsigned short port = SERVER_PORT;

	void InitServer();
	void InitClient();

};

ReversiEngine::ReversiEngine()
{
}

ReversiEngine::~ReversiEngine()
{
}

#endif // !REVERSIH
