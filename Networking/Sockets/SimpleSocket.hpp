/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 12:59:52 by asabbar           #+#    #+#             */
/*   Updated: 2023/01/01 18:04:57 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLESOCKET_HPP
# define SIMPLESOCKET_HPP

# include <iostream>
# include <string>
#include <sys/socket.h>
#include <netinet/in.h>

class SimpleSocket
{
	public:
		// Constructors
		SimpleSocket();

		SimpleSocket(int domain, int service, int protocol, int port, u_long interface);


		
		SimpleSocket(const SimpleSocket &copy);
		
		virtual int connectionToSocket(int sock, struct sockaddr_in address) = 0;
		
		
		
	
		void testCnnection (int);
		
		
		
		
		struct sockaddr_in get_address ();
		
		int get_sock ();
		
		int get_connection ();
		
		

		void	set_connection(int);

		
		~SimpleSocket();
		
		// Operators
		SimpleSocket & operator=(const SimpleSocket &assign);
		 
	private:
		int connection;
		int sock;
		struct sockaddr_in address;
};

#endif