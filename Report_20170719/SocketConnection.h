#ifndef SOCKETCONNECTIONH
#define SOCKETCONNECTIONH

#define SERVER_PORT 50622

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
