#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <netdb.h>
#include  <arpa/inet.h>

int main(void){
    char cadena[100];
    int listen_fd, comm_fd;
    struct sockaddr_in servaddr;   
    char sendline[100] = "using port 22222";

    listen_fd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
     
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22222);

    bind(listen_fd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    listen(listen_fd,5);
    comm_fd = accept(listen_fd,(struct sockaddr*) NULL,NULL);

    printf("Succesfulll connection\n");

    while(!strstr(cadena,"Endit")&& !strstr(sendline, "Endit")){
        bzero(cadena ,100);
        printf("Client: ");
        read(comm_fd,cadena,100);
        printf("%s",cadena);
        if(!strstr(cadena,"Endit")){
            printf("\nServer: ");
	    gets(sendline);
            write(comm_fd,sendline,strlen(sendline)+1);
        }
    }
printf("\nConnection ended\n");
}

