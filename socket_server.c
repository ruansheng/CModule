#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#define MYPORT  8887
#define QUEUE   20
#define BUFFER_SIZE 1024

int main()
{
    int server_sockfd = socket(AF_INET,SOCK_STREAM, 0);

    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(MYPORT);
    server_sockaddr.sin_addr.s_addr =INADDR_ANY;

    if(bind(server_sockfd,(struct sockaddr *)&server_sockaddr,sizeof(server_sockaddr))==-1){
        printf("bind fail \r\n");
        exit(1);
    }
	
    if(listen(server_sockfd,QUEUE) == -1){
        printf("listen fail \r\n");
        exit(1);
    }
	
    printf("正在监听...\r\n");

    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);

    while(1){
	    int conn = accept(server_sockfd, (struct sockaddr*)&client_addr, &length);
	    if(-1==conn){
	        printf("connect fail");
	        exit(1);
	    }
	puts("正在接收数据...\r\n");
        memset(buffer,0,sizeof(buffer));
        int len = recv(conn, buffer, sizeof(buffer),0);
	puts(buffer);
        send(conn, buffer, len, 0);
        printf("发送完成!\r\n");
		close(conn);
    }
    close(server_sockfd);
    return 0;
}

