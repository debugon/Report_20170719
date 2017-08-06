#ifndef SOCKETCONNECTIONH
#define SOCKETCONNECTIONH

#define SERVER_PORT 50622

#include<iostream>
#include<WinSock2.h>

//SystemType::Noneにしたいが、Reversi.hで再定義エラーが出るので変える
enum SystemType { Other, Server, Client };

class SocketConnection
{
public:
	SocketConnection();
	~SocketConnection();

private:
	SystemType systemType = SystemType::Other;

	int result;
	char buffer[1000];
	const unsigned short port = SERVER_PORT;

	int InitServer(unsigned short port, SOCKET* soc);
	int InitClient();
};
#endif // !SOCKETCONNECTIONH
