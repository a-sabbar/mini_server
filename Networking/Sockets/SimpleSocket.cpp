/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleSocket.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:59:49 by asabbar           #+#    #+#             */
/*   Updated: 2023/01/04 11:10:45 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SimpleSocket.hpp"
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
// Constructors
SimpleSocket::SimpleSocket()
{
	std::cout << "\e[0;33mDefault Constructor called of SimpleSocket\e[0m" << std::endl;
}






SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{

	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(interface);


	int opt = 1;
	
	sock = socket(domain, service, protocol);
	testCnnection(sock);
	int option = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(1));
}



void	SimpleSocket::set_connection(int conn){
	
	connection = conn;
	
}








void SimpleSocket::testCnnection (int item)
{
	if(item < 0)
	{
		perror("Failed to connect 0_0 ");
		exit(1);
	}
	return ;
}








struct sockaddr_in SimpleSocket::get_address()
{
	return (address);
}



int SimpleSocket::get_sock()
{
	return (sock);
}


int SimpleSocket::get_connection()
{
	return (connection);
}














SimpleSocket::SimpleSocket(const SimpleSocket &copy)
{
	(void) copy;
}


// Destructor
SimpleSocket::~SimpleSocket()
{
}


// Operators
SimpleSocket & SimpleSocket::operator=(const SimpleSocket &assign)
{
	(void) assign;
	return *this;
}

