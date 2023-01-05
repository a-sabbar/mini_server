#include "listeningSocket.hpp"

// Constructors
listeningSocket::listeningSocket()
{
}

listeningSocket::listeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg) : BindingSocket(domain, service, protocol, port, interface)
{
	backlog = bklg;
	start_lestening();
	testCnnection(listening);
}

void listeningSocket::start_lestening()
{
	listening = listen(get_sock(), backlog);
}

listeningSocket::listeningSocket(const listeningSocket &copy)
{
	(void)copy;
}

// Destructor
listeningSocket::~listeningSocket()
{
}

// Operators
listeningSocket &listeningSocket::operator=(const listeningSocket &assign)
{
	(void)assign;
	return *this;
}
