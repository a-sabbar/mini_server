#ifndef SIMPLESERVER_HPP
#define SIMPLESERVER_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include "../Sockets/hdelibcsockets.hpp"

#include <vector>
#include <sstream>

class SimpleServer
{
public:
	// Constructors
	SimpleServer();

	SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklg);

	virtual void launch() = 0;

	listeningSocket *get_socket();

	SimpleServer(const SimpleServer &copy);

	// Destructor
	~SimpleServer();

	// Operators
	SimpleServer &operator=(const SimpleServer &assign);

private:
	listeningSocket *socket;
};


#endif