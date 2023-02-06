#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include<netdb.h>
#include <arpa/inet.h>

int main(void){
    char cadena[100];
    int sock_fd;
    struct sockaddr_in servaddr;
    char sendline[100] = "using port 22222";

    sock_fd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(22222);

    inet_pton(AF_INET,"192.168.100.31",&(servaddr.sin_addr));
    connect(sock_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    printf("Successfull connection\n");

    while(!strstr(cadena, "Endit")&& !strstr(sendline,"Endit")){
        bzero(cadena,100);
        printf("\nClient: ");
        gets(sendline);
        write(sock_fd,sendline,strlen(sendline)+1);
        if(!strstr(cadena,"Endit")){
	    bzero(cadena,100);
    	    printf("Server:");
            read(sock_fd,cadena,100);
	    printf("%s",cadena);
        }
    }
printf("\nConnection ended\n");

}   
