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
            char request[10000000];
            int i;
                strcpy(arg, argv[1]);

        for (i = 0; i < strlen(arg); i++)
            {
                if (arg[i] == '/')
                {
                        strncpy(firstHalf, arg, i);
                        firstHalf[i+1] = '\0';
                        break;
                }
            }

            for (i; i < strlen(arg); i++)
            {
                strcat(secondHalf, &arg[i]);
                if(&arg[i]=='\0'){
		//	secondHalf[i]='\0';
		}
		break;
            }
		if(secondHalf[0]=='/')
		{
		//	secondHalf[0]=" ";
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
      	struct sockaddr_in sinServer;
	bzero((char *) &sinServer, sizeof(sinServer));      
	//memset(&sinServer, 0, sizeof(struct SOCKADDR *));
      	sinServer.sin_family = PF_INET;
	bcopy((char*)hostServer->h_addr, (char *)&sinServer.sin_addr,sizeof((char *)hostServer->h_addr) );
//,siServer.h_length);
      	sinServer.sin_port = htons(80);
     //	sinServer.sin_addr = *((IN_ADDR *)hostServer>h_addr_list[0]);

//send and receive root



//send(tcpsocket, buf, strlen(buf), flags);
    if (connect(tcpsocket, (struct sockaddr *) &sinServer, sizeof(sinServer)) < 0)
        printf("\nError Connecting");
    else
        printf("\nSuccessfully Connected");
   
    bzero(request, 1000);
 
    sprintf(request, "GET %s HTTP/1.1 \n HOST: %s \n\n", secondHalf+3, firstHalf);
    printf("\n%s", request);
    //printf("\n%s", request);
     printf("before send\n");
    if (send(tcpsocket, request, strlen(request), 0) < 0){
        printf("Error with send()");
	}
    else{
        printf("\nSuccessfully sent html fetch request");
	}
    printf("after send\n");
    
	bzero(request, 1000);
	printf("\nrequest: %s\n", request);
    
	recv(tcpsocket, request, 999, 0);
	printf("\nrequest recieve:%s", request);
    

	printf("\nhello");
     
    close(tcpsocket);
	
	
}

