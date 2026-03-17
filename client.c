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
	
	// Create socket
	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(client_fd < 0)
	{
		perror("Creating socket is failed");
		exit(EXIT_FAILURE);
	}

	printf("Socket successfully created\n");


	return 0;
}

