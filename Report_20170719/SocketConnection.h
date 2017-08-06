#ifndef SOCKETCONNECTIONH
#define SOCKETCONNECTIONH

#define SERVER_PORT 50622

#include<iostream>
#include<string>
#include<WinSock2.h>

//SystemType::None�ɂ��������AReversi.h�ōĒ�`�G���[���o��̂ŕς���
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
	int InitClient(std::string server, unsigned short port, SOCKET* soc);
};
#endif // !SOCKETCONNECTIONH
