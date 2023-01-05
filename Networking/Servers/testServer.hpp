#ifndef TESTSERVER_HPP
# define TESTSERVER_HPP

# include <iostream>
# include <string>
#include "SimpleServer.hpp"
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>


class testServer : public SimpleServer
{
	private:
		char buffer[300000];
		void accepter();
		void handler();
		void responder();
		int new_socket;
		std::string path;
	public:
		// Constructors
		testServer(int port);
		
		
		
		// testServer(int domain, int service, int protocol, int port, u_long interface, int bklg);
		
		
		
		
		
		
		void launch();
		
		
		
		
		
		
		testServer(const testServer &copy);
		// Destructor
		~testServer();
		
		// Operators
		testServer & operator=(const testServer &assign);
		
		
};

#endif