#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void)
{
	int server_fd, client_fd;
	struct sockaddr_in server_addr;


	// Create socket
	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(client_fd < 0)
	{
		perror("Creating socket is failed");
		exit(EXIT_FAILURE);
	}

	printf("Socket successfully created\n");

	// Connect to the server
	if(connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0 )
	{
		perror("Connection failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Connection successful\n");

	return 0;
}

