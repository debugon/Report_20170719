#include"SocketConnection.h"

SocketConnection::SocketConnection()
{

}

SocketConnection::~SocketConnection()
{

}

int SocketConnection::InitServer(unsigned short port, SOCKET* soc)
{
	WSADATA wsaData;
	SOCKET listenSoc;
	SOCKADDR_IN saddr, from;
	int fromlen, ret;

	ret = WSAStartup(MAKEWORD(1, 1), &wsaData);
	if (ret) {
		std::cout << "Soket Error!" << std::endl;
		return -1;
	}

	listenSoc = socket(AF_INET, SOCK_STREAM, 0);
	if (listenSoc < 0) {
		std::cout << "Socket Open Error!" << std::endl;
		WSACleanup();
		return -1;
	}

	ZeroMemory(&saddr, sizeof(SOCKADDR_IN));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = INADDR_ANY;
	if (bind(listenSoc, (struct sockaddr *)&saddr, sizeof(saddr)) == SOCKET_ERROR) {
		std::cout << "Socket Bind Error!" << std::endl;
		closesocket(listenSoc);
		WSACleanup();
		return -1;
	}

	if (listen(listenSoc, 0) == SOCKET_ERROR) {
		std::cout << "Listen Error!" << std::endl;
		closesocket(listenSoc);
		WSACleanup();
		return -1;
	}
	else {
		std::cout << "Wait Client Connection..." << std::endl;
		std::cout << "[ctrl + C]...END" << std::endl;
	}

	fromlen = sizeof(from);

	*soc = accept(listenSoc, (SOCKADDR *)&from, &fromlen);
	if (*soc == INVALID_SOCKET) {
		std::cout << "Accept Error!" << std::endl;
		closesocket(listenSoc);
		WSACleanup();
		return -1;
	}
	else {
		std::cout << inet_ntoa(from.sin_addr) << " Connected." << std::endl;
	}
	closesocket(listenSoc);

	return 0;
}

int SocketConnection::InitClient(std::string server, unsigned short port, SOCKET* soc)
{
	WSADATA wsaData;
	HOSTENT* host;
	unsigned int addr;
	SOCKADDR_IN saddr;
	int ret;

	ret = WSAStartup(MAKEWORD(1, 1), &wsaData);
	if (ret) {
		std::cout << "Soket Error!" << std::endl;
		return -1;
	}

	*soc = socket(AF_INET, SOCK_STREAM, 0);
	if (*soc < 0) {
		std::cout << "Socket Open Error!" << std::endl:
		WSACleanup();
		return -1;
	}

	host = gethostbyname(server.c_str());
	if (!host) {
		addr = inet_addr(server.c_str());
		host = gethostbyaddr((char *)&addr, 4, AF_INET);
	}
	if (!host) {
		std::cout << "Host Name Error!" << std::endl;
		closesocket(*soc);
		WSACleanup();
		return -1;
	}

	ZeroMemory(&saddr, sizeof(SOCKADDR_IN));
	saddr.sin_family = host->h_addrtype;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = *((u_long *)host->h_addr);

	if (connect(*soc, (SOCKADDR *)&saddr, sizeof(saddr)) == SOCKET_ERROR) {
		std::cout << "Connection Error!" << std::endl;
		closesocket(*soc);
		WSACleanup();
		return -1;
	}

	return 0;
}
