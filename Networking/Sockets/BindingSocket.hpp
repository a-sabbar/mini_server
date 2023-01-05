/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BindingSocket.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:31:26 by asabbar           #+#    #+#             */
/*   Updated: 2023/01/01 15:47:50 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINDINGSOCKET_HPP
# define BINDINGSOCKET_HPP

# include <iostream>
# include <string>
#include "SimpleSocket.hpp"

class SimpleSocket;

class BindingSocket : public SimpleSocket
{
	public:
		// Constructors
		BindingSocket();
		
		
		
		BindingSocket(int domain, int service, int protocol, int port, u_long interface);
		
		
		
		
		int connectionToSocket(int sock, struct sockaddr_in address);


		
		
		
		
		// Destructor
		~BindingSocket();
		
		// Operators
		BindingSocket & operator=(const BindingSocket &assign);
		
	private:
		
};

#endif