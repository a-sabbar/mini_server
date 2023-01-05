#include "SimpleServer.hpp"

// Constructors
SimpleServer::SimpleServer()
{
}

SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklg)
{
	socket = new listeningSocket(domain, service, protocol, port, interface, bklg);
}

listeningSocket *SimpleServer::get_socket()
{
	return socket;
}

SimpleServer::SimpleServer(const SimpleServer &copy)
{
	(void)copy;
}

// Destructor
SimpleServer::~SimpleServer()
{
}

// Operators
SimpleServer &SimpleServer::operator=(const SimpleServer &assign)
{
	(void)assign;
	return *this;
}
