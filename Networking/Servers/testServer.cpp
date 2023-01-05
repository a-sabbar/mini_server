#include "testServer.hpp"

// Constructors
testServer::testServer(int port) : SimpleServer(AF_INET, SOCK_STREAM, 0, port, INADDR_ANY, 10)
{
	launch();
}



std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

char	*move(char *s1, char *s2, char *s)
{
	int		a;
	int		i;

	a = strlen(s1);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
	}
	i = 0;
	while (s2[i])
	{
		s[a] = s2[i];
		a++;
		i++;
	}
	s[a] = '\0';
	return (s);
}

char	*strjoin(char *s1, char *s2)
{
	int		a;
	int		i;
	char	*s;

	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	a = strlen(s1);
	s = (char *)malloc(a + strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	s = move(s1, s2, s);
	free(s1);
	return (s);
}


void testServer::accepter()
{
	struct sockaddr_in address = get_socket()->get_address();
	int addrlen = sizeof(address);
	new_socket = accept(get_socket()->get_sock(), (sockaddr *)&address, (socklen_t *)&addrlen);
	bzero(buffer, sizeof(buffer));
	read(new_socket, buffer, sizeof(buffer));
}

void testServer::handler()
{
	std::cout << "{{{\n\n"<< buffer <<  " \n}\n";

	std::vector<std::string> ::iterator it = split(*(split(buffer, '\n').begin()), ' ').begin();
	it++;
	std::cout<< *it << std::endl;
	path = (*it);
}

void testServer::responder()
{

	std::string value;
	std::ifstream  file;
	std::ifstream  fileError;
    file.open("." + path);
	if(!file.is_open())
	{
    	fileError.open("error404.html");
		getline(fileError , value, '\0');
		std::string len = std::to_string(value.length());
		value = "HTTP/1.1 404 KO\r\nContent-Type: text/html\r\nContent-Length: " + len + "\r\n\r\n" + value;
	}
	else if(!path.compare("/"))
	{
    	fileError.open("home.html");
		getline(fileError , value, '\0');
		std::string len = std::to_string(value.length());
		value = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: " + len + "\r\n\r\n" + value;
	}
	else
	{
		getline(file , value, '\0');
		std::string len = std::to_string(value.length());
		value = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: " + len + "\r\n\r\n" + value;
	}
	write(new_socket, (char *)value.c_str(), value.length());
	close (new_socket);

}

void testServer::launch()
{
	while(1)
	{
		std::cout << "============== WAITING ==============\n";
		accepter();
		handler();
		responder();
		std::cout <<"============== DONE ==============\n";
 	}

}

testServer::testServer(const testServer &copy)
{
	(void)copy;
}

// Destructor
testServer::~testServer()
{
}

// Operators
testServer &testServer::operator=(const testServer &assign)
{
	(void)assign;
	return *this;
}

// GET / HTTP/1.1
// Host: 127.0.0.1
// User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.14; rv:94.0) Gecko/20100101 Firefox/94.0
// Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8
// Accept-Language: en-US,en;q=0.5
// Accept-Encoding: gzip, deflate
// Connection: keep-alive
// Upgrade-Insecure-Requests: 1
// Sec-Fetch-Dest: document
// Sec-Fetch-Mode: navigate
// Sec-Fetch-Site: none
// Sec-Fetch-User: ?1
// Cache-Control: max-age=0