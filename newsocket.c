//Rachel McGuigan
#include<arpa/inet.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>

//ask for url
//request host name
//socket bind
//run forever for connecting packets of file on server
//http get send wait
//display page 
//connet here
//
//given the file is ran with a url then the hostname that the server is runing on/ 

int main(int argc, char *argv[]){

        struct hostent *server;
        struct sockaddr_in si_server;

        char arg[500];
            char firstHalf[500];
            char secondHalf[500];
            char request[1000];
            int i;
                strcpy(arg, argv[1]);

        for (i = 0; i < strlen(arg); i++)
            {
                if (arg[i] == '/')
                {
                        strncpy(firstHalf, arg, i);
                        firstHalf[i] = '\0';
                        break;
                }
            }

            for (i; i < strlen(arg); i++)
            {
                strcat(secondHalf, &arg[i]);
                break;
            }

            printf("\nFirst Half: %s\n", firstHalf);
            printf("\nSecond Half: %s\n", secondHalf);


//SOCKET socket(int af, int type, int protocol);
//af protocol family address
//this case AF_INET socket type
//type  is communication type
//SOCK_STREAM is TCP
//protocol TCP= IPPROTO_TCP
//
//
//Create a Socket
	int tcpsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//Check socket

	if(tcpsocket < 0){
		printf("socket error\n");
		exit;
	}	

//connect
//int connect (SOCKET s, const struct sockaddr *name, int namelen);
//sockaddr name SOCKADDR_IN, which identifies the server
//namelen is length of buffer for server name

//// First, get the host information
	struct	hostent *hostServer = gethostbyname(firstHalf);
	if(hostServer == NULL) {
      		printf("hostname error\n");
		exit;
      	}

//      // Set up the target device address structure
      	struct SOCKADDR *sinServer;
	bzero((char *) &sinServer, sizeof(sinServer));      
	//memset(&sinServer, 0, sizeof(struct SOCKADDR *));
      	sinServer.sin_family = PF_INET;
	bcopy((char*)server->h_addr, (char *)&sinServer.sin_addr, sinServer->h_length);
      	sinServer.sin_port = htons(80);
     	 sinServer.sin_addr = *((IN_ADDR *)hostServer>h_addr_list[0]);

         // Connect with a valid socket
         if(connect(tcpsocket, (sockaddr *)&sinServer, sizeof(sinServer))== SOCKET_ERROR) {
          int iSocketError = WSAGetLastError();
                  return FALSE;
                  }

//send and receive root
//

while(1){

//send(tcpsocket, buf, strlen(buf), flags);
    if (connect(tcpSocket, (struct sockaddr *) &sinServer, sizeof(sinServer)) < 0)
        printf("\nError Connecting");
    else
        printf("\nSuccessfully Connected");
   
    bzero(request, 1000);
 
    sprintf(request, "Get %s HTTP/1.1\r\n Host: %s\r\n \r\n \r\n", secondHalf, firstHalf);
     
    printf("\n%s", request);
     
    if (send(tcpSocket, request, strlen(request), 0) < 0)
        printf("Error with send()");
    else
        printf("Successfully sent html fetch request");
     
    bzero(request, 1000);
     
    recv(tcpSocket, request, 999, 0);
    printf("\n%s", request);
    printf("\nhello");
     
    close(tcpSocket);

}

	//send
	//send(SOCKET, char buf, int len, int flags)
	
	//receive







