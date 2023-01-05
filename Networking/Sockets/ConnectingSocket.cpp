#include "ConnectingSocket.hpp"

// Constructors
ConnectingSocket::ConnectingSocket()
{
}
ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interface) : SimpleSocket(domain, service, protocol, port, interface)
{
	set_connection(connectionToSocket(get_sock(), get_address()));
	testCnnection(get_connection());
}

int ConnectingSocket::connectionToSocket(int sock, struct sockaddr_in address)
{
	return connect(sock, (struct sockaddr *)&address, sizeof(address));
}

// Destructor
ConnectingSocket::~ConnectingSocket()
{
}

// Operators
ConnectingSocket &ConnectingSocket::operator=(const ConnectingSocket &assign)
{
	(void)assign;
	return *this;
}
