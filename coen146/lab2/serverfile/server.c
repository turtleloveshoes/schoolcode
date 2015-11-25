#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<strings.h>
#include<stdlib.h>
#define SERVER_PORT 50009

int main(){

struct sockaddr_in si_server;

socklen_t addr_len;

char red[1000]; 

int lengthofhost;

/*server = gethostbyname(argv[1]);
if(server==NULL){
	fprintf(stderr, "Error no such host");
	exit(0);
}

puesdo
 * build socket
open server passive pf inet
bind socket to address
receive data
bnind <0
	error on binding

while(1)
 revform guiffer
*/
/*Build the socket*/
                /*Sets the feilds in si_server*/
                bzero((char *) &si_server, sizeof(si_server));
                /*symbolic constant that gets the address AN-INET*/
                si_server.sin_family = AF_INET;

              //  bcopy((char *) si_server->h_addr,(char *) &si_server.sin_addr,server->h_length);
		si_server.sin_addr.s_addr=INADDR_ANY;
                si_server.sin_port = htons(SERVER_PORT);
/* Open a socket*/
                /*domain, type, protocol */
                int sockfd =socket(PF_INET, SOCK_DGRAM, 0);
                        if(sockfd <0)
                                error("ERROR opening socket try later");
/*Server Bind address to the socket This function takes to pointers and creates a channel between the port number of the host and the client*/
	if(bind(sockfd, (struct sockaddr *) &si_server, sizeof(si_server))<0)
		error("ERROR on binding");

lengthofhost=sizeof(si_server);
printf("recieve/n");
while(1){

  /*SERVER Receive from client*/
                /*filedescriptor, bufferreadby, max bytes, flags, pointer to cockaddr, size*/
               int n = recvfrom(sockfd,red,1024,0,(struct sockaddr*) &si_server,&addr_len);
                printf(red);
		if (n<0){
                        error("recvfrom");
		 }
	}
}
