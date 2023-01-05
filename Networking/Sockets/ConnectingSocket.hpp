#ifndef CONNECTINGSOCKET_HPP
# define CONNECTINGSOCKET_HPP

# include <iostream>
# include <string>
# include "SimpleSocket.hpp"

class SimpleSocket;


class ConnectingSocket : public SimpleSocket
{
	public:
		// Constructors
		ConnectingSocket();


		ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);



		int connectionToSocket(int sock, struct sockaddr_in address);

		
		// Destructor
		~ConnectingSocket();
		
		// Operators
		ConnectingSocket & operator=(const ConnectingSocket &assign);
		
	private:
		
};

#endif