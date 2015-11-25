/*
 *  Created by Rachel  McGuigan on 5/17/12.
 *  Copyright 2012 Santa Clara University. All rights reserved.
 *
 */
#include<arpa/inet.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
#define PORT 4456

//main accepts url request
int main (int argc, char *argv[]){
            char arg[500];
            char firstHalf[500];
            char secondHalf[500];
            char request[10000000];
	char recieve[1000000];
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

struct hostent *server;
struct sockaddr_in si_server;
struct	hostent *hostServer = gethostbyname(firstHalf);
if(hostServer == NULL) {
	printf("hostname error\n");
	exit;
}

//      // Set up the target device address structure
struct sockaddr_in sinServer;
bzero((char *) &sinServer, sizeof(sinServer));      

sinServer.sin_family = PF_INET;
bcopy((char*)hostServer->h_addr, (char *)&sinServer.sin_addr,sizeof((char *)hostServer->h_addr) );

sinServer.sin_port = htons(PORT);
//	sinServer.sin_addr = *((IN_ADDR *)hostServer>h_addr_list[0]);

//send and receive root

//I am a server always listening
while(1){
	//Create a Socket
	int tcpsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	//Check socket
	if(tcpsocket < 0){
		printf("socket error\n");
		exit;
	}	
	
	//bind
	if(bind(sockfd, (struct sockaddr *) &si_server, sizeof(si_server))<0){
		error("ERROR on binding");
	}
	int lengthofhost=sizeof(si_server);
	printf("recieve/n");
		
		//listen and recive from browser
		while (recv(tcpsocket, request, 999, 0)>0) {
					
			bzero(request, 1000);
			printf("\nrequest: %s\n", request);	
			sprintf(recieve[i],"%s", request);
			i=i+1000;
		//STOP LISTENING WHEN A REQUEST IS RECIEVED FROM THE BROWSER
		}
		//when done recieving unpack the hostname and file name

	
}
	//GET HOST OF SERVER PROJ 2
	struct hostent *server2;
	struct sockaddr_in si_server2;
	struct	hostent *hostServer2 = gethostbyname(firstHalf);
	if(hostServer2 == NULL) {
		printf("hostname error\n");
		exit;
	}

	//  BIND AND SOCKET WEBSERVER2    // Set up the target device address structure
	struct sockaddr_in sinServer2;
	bzero((char *) &sinServer2, sizeof(sinServer2));      

	sinServer2.sin_family = PF_INET;
	bcopy((char*)hostServer2->h_addr, (char *)&sinServer2.sin_addr,sizeof((char *)hostServer2->h_addr) );

	sinServer2.sin_port = htons(80);
		
	//create a socket
	int tcpsocket2 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//Check socket

	if(tcpsocket2 < 0){
		printf("socket error webserver\n");
		exit;
	}	
	//bind
	if(bind(sockfd, (struct sockaddr *) &si_server2, sizeof(si_server2))<0){
		error("ERROR on binding webserver\n");
	}
	
	lengthofhost=sizeof(si_server2);
	
	
	
	while (send(tcpsocket, request, strlen(request), 0) > 0) {
		//SEND AND RECIEVE FROM WEBSERVER
		bzero(request, 1000);
		printf("before send\n");
		if (send(tcpsocket, request, strlen(request), 0) < 0){
			printf("Error with send()");
		}
		else{
			printf("\nSuccessfully sent html fetch request");
		}
		//OPEN FILE AND WRITE TO CACHE WHILE RECIEVEING 
		//ADD HERE
		printf("after send\n");
		bzero(request, 1000);
		printf("\nrequest: %s\n", request);
	}
	//RECIEVE-LISTEN
	while( recv(tcpsocket, request, 999, 0)!=0){
	printf("\nrequest recieve:%s", request);
		if(request!=0){
			bzero(request, 1000);
			printf("\nrequest recieve:%s", request);
		}
   	}
	printf("\nhello");
		printf("\nrequest recieve:%s", request);
 
    close(tcpsocket);		
		
	}

//EXTRA CODE
bzero(request, 1000);
	/*Depending if it is an update cache request or a proxy request the switch satement will change*/
	int x=0;
	x=2;
	switch(x){
		case 1:
		{
			//send the request
			sprintf(request, "GET %s HTTP/1.1 \nHOST: %s \n\n", secondHalf, firstHalf);
					printf("\n%s", request);
			//copy to cache
			FILE newfile;
			fopen("newfile.html", newfile)
			while(request!="/0"){
				fwrite(request, newfile);
			}
			fclose(filename);
			//open browser
			char url[500];
			strcpy(url, "firefox ");
			//strcpy(url,sprintf("%s", arg));
			system(url);
		}
		case 2:{
			sprintf(request, "GET %s HTTP/1.1\nHost:%s\nUser-Agent: Mozilla/5.0 (Windows NT 5.1; rv:9.0) Gecko/20100201 Firefox/9.0\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9*/*;q=0.8text/plain,application/*\nAccept-Language: en-us,en;q=0.5\nIf-Modified-Since: Tues, 31 Jan 2010 10:50:12 GMT\nCache-Control: max-age=2\n", secondHalf, firstHalf); 
			printf("\n%s", request);
			//no?
			x=1;
			//yes then open local cache webpage
			system(firefox "filepath");
		}
			
	}
	printf("\n%s", request);
	

}
