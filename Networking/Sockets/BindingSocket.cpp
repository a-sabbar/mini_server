/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BindingSocket.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:31:24 by asabbar           #+#    #+#             */
/*   Updated: 2023/01/01 18:08:50 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BindingSocket.hpp"

// Constructors

BindingSocket::BindingSocket()
{
}

BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface) : SimpleSocket(domain, service, protocol, port, interface)

{
	set_connection(connectionToSocket(get_sock(), get_address()));
	testCnnection(get_connection());
}

int BindingSocket::connectionToSocket(int sock, struct sockaddr_in address)
{
	return bind(sock, (struct sockaddr *)&address, sizeof(address));
}

// Destructor
BindingSocket::~BindingSocket()
{
}

// Operators
BindingSocket &BindingSocket::operator=(const BindingSocket &assign)
{
	(void)assign;
	return *this;
}
