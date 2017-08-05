#ifndef SOCKETCONNECTIONH
#define SOCKETCONNECTIONH

#define SERVER_PORT 50622

#include<WinSock2.h>

enum SystemType { None, Server, Client };

class SocketConnection
{
public:

private:
	SystemType systemType = SystemType::None;

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
#endif // !SOCKETCONNECTIONH
