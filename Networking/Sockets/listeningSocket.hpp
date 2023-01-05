/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listeningSocket.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:24:04 by asabbar           #+#    #+#             */
/*   Updated: 2023/01/01 18:13:56 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTENINGSOCKET_HPP
#define LISTENINGSOCKET_HPP

#include <iostream>
#include <string>
#include "SimpleSocket.hpp"
#include "BindingSocket.hpp"

class listeningSocket : public BindingSocket
{
public:
	// Constructors
	listeningSocket();

	listeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg);

	void start_lestening();

	listeningSocket(const listeningSocket &copy);

	// Destructor
	~listeningSocket();

	// Operators
	listeningSocket &operator=(const listeningSocket &assign);

private:
	int backlog;
	int listening;
};

#endif