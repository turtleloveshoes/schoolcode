
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
                        firstHalf[i] = '\0';
                     printf("first half loop: %s\n length: %d", firstHalf, strlen(firstHalf));
			printf("arg: %s\n",arg);
			   break;
                }
            }

            for (i=strlen(firstHalf); i < strlen(arg); i++)
            {
                strcpy(secondHalf, &arg[i]);
               printf("i:%d\n", i);
		if(&arg[i]=='\0'){
			secondHalf[i]='\0';
		}
                     printf("second half loop: %s\n length: %d", secondHalf, strlen(secondHalf));
		break;
            }
            
	printf("\nFirst Half: %s\n", firstHalf);
            printf("\nsecong Half: %s\n", secondHalf);

/*This is the requestpart*/

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
 /*Depending if it is an update cache request or a proxy request the switch satement will change*/
int x=0;
x=2;
switch(x){
 	case 1:
	{
	//send the request
	   sprintf(request, "GET %s HTTP/1.1 \nHOST: %s \n\n", secondHalf, firstHalf);
	//copy to cache
	//open browser
	char url[500];
	strcpy(url, "firefox ");
	//strcpy(url,sprintf("%s", arg));
	system(url);
	}
	case 2:{
    	sprintf(request, "GET %s HTTP/1.1\nHost:%s\nUser-Agent: Mozilla/5.0 (Windows NT 5.1; rv:9.0) Gecko/20100201 Firefox/9.0\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9*/*;q=0.8text/plain,application/*\nAccept-Language: en-us,en;q=0.5\nIf-Modified-Since: Tues, 31 Jan 2010 10:50:12 GMT\nCache-Control: max-age=2\n", secondHalf, firstHalf); 
	}
	
	}
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
    
	while(1){
       recv(tcpsocket, request, 999, 0);
	printf("\nrequest recieve:%s", request);
    }
	printf("\nhello");
 
    close(tcpsocket);
}	
