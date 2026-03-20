#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080


int main(void)
{
	int server_fd, client_fd;
	struct sockaddr_in server_addr, client_addr;
	char buffer[1024] = {0};

	// Create socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_fd < 0)
	{
		perror("Creating socket failed");
		exit(EXIT_FAILURE);
	}
	printf("Socket successfully created\n");

	// assign IP, PORT
	server_addr.sin_family = AF_INET; // IPV4
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	// binding socket to IP, PORT
	if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)))
	{
		perror("socket bind failed...\n");
		exit(EXIT_FAILURE);
	}

	printf("binding successfully\n");

	// Now server is ready to listen
	if((listen(server_fd, 5)) != 0)
	{
		perror("Listening failed....\n");
		exit(EXIT_FAILURE);
	}

	printf("Server is listening on port 8080...\n");

	// accept connection from client
	socklen_t addrlen = sizeof(client_addr);
	client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addrlen);

	printf("Client is connected\n");

	// Receive data from client
	recv(client_fd, buffer, sizeof(buffer), 0);
	printf("Client message: %s\n", buffer);

	// Send data to client
	const char *response = "Hey, from server!";
	send(client_fd, response, sizeof(response), 0);

	close(server_fd);
	close(client_fd);

	
	return 0;
}
