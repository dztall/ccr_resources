#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <pthread.h>

#include <ccr.h>

int sock;
char server_reply[4000];
pthread_t thread;
pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;
bool exitReceiveThread = false;

void receive(void *param)
{
	server_reply[0] = 0;
	int message_size = 0;
	while (!exitReceiveThread)
	{
		usleep(1000);

		char buf[2000];
		int recvSize = recv(sock, buf, 1999, 0);
		if (recvSize < 0)
			continue;
		else
		{
			buf[recvSize] = 0;

			pthread_mutex_lock(&mutex);
			strcat(server_reply, buf);
			pthread_mutex_unlock(&mutex);

			message_size += recvSize;
			if (message_size >= 2000)
				break;
		}
	}
}

void exit_handler()
{
	exitReceiveThread = true;
	pthread_join(thread, NULL);
	pthread_mutex_destroy(&mutex);
	close(sock);
}

int main(int argc, char *argv[])
{
	atexit(exit_handler);

	printf("Chatting client 1.0.0 for Mobile C\n");
	printf("Input empty text to refresh incoming messages.\n\n");

	struct sockaddr_in server;
	char message[1000];

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		printf("Could not create socket.");

	server.sin_addr.s_addr = inet_addr("61.75.40.213");
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);

	if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("Connection failed.");
		return 1;
	}

	int flags = fcntl(sock, F_GETFL, 0);
	if (fcntl(sock, F_SETFL, flags | O_NONBLOCK) == -1)
	{
		perror("Listen socket non-blocking.");
		return -1;
	}

	//Disable nagle's algorithm.
	int flag = 1;
	setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char *)&flag, sizeof(int));

	pthread_create(&thread, NULL, receive, NULL);

	//Wait for server welcome message.
	usleep(1000 * 1000);

	while (ccrGetEvent(true) != CCR_EVENT_QUIT)
	{
		pthread_mutex_lock(&mutex);
		if (server_reply[0])
		{
			printf("%s", server_reply);
			server_reply[0] = 0;
		}
		pthread_mutex_unlock(&mutex);

		printf("You : ");

		message[0] = 0;
		while (true)
		{
			char buf[1024];
			buf[0] = 0;

			int n = scanf("%[^\n]", buf);
			if (n > 0)
				strcat(message, buf);

			char c;
			int n1 = scanf("%c", &c);
			int n2 = scanf("%[^\n]", buf);

			if (n <= 0 && (n1 <= 0 || n2 <= 0))
				break;

			if (n1 > 0)
				strcat(message, "\n");
			if (n2 > 0)
				strcat(message, buf);

			int n3 = scanf("%c", &c);
			if (n3 > 0)
				strcat(message, "\n");
		}

		if (message[0])
		{
			if (send(sock, message, strlen(message) + 1, 0) < 0)
			{
				puts("Send failed");
				return 1;
			}
		}
	}

	return 0;
}
