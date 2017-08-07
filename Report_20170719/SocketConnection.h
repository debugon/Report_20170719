#ifndef SOCKETCONNECTIONH
#define SOCKETCONNECTIONH

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define SERVER_PORT 50622

#include<iostream>
#include<string>
#include<WinSock2.h>

//SystemType::Noneにしたいが、Reversi.hで再定義エラーが出るので変える
enum SystemType { Other, Server, Client };

class SocketConnection
{
public:
	SocketConnection();
	~SocketConnection();

	SystemType GetSystemType() { return systemType; }
	void SetSystemType(SystemType inputType) { systemType = inputType; }

private:
	SystemType systemType = SystemType::Other;

	const unsigned short port = SERVER_PORT;
	SOCKET soc;
	int rcv;
	std::string server;

	int InitServer(unsigned short port, SOCKET* soc);
	int InitClient(std::string server, unsigned short port, SOCKET* soc);
};
#endif // !SOCKETCONNECTIONH
