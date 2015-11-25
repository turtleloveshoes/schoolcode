//Client request to server socket bind and 
//Rachel McGuigan 
#include<stido.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
#define SERVER_PORT 50009

//ask for url
//request host name
//socket bind
//run forever for connecting packets of file on server
//http get send wait
//display page 
//connet here
//
//given the file is ran with a url then the hostname that the server is runing on/ 
void main(int argc, char *argv[]){

	struct hostent *server;
	struct sockaddr_in si_server;	
        
		
	char *url;
	strcpy(*url, argv[0]);
	//urlfirst hostname
	char urlfirst[];
	urlfirst[0]=strtok(url, "/");
	print("hostname: %s\n", urlfirst[])
	//url file path


	/*deal with server*/
	server=gethostbyname(argv[1]);
	/*Make sure the server is there*/
	if (server == NULL){
		fprintf(stderr, "ERROR, no such host");
		exit(0);
	}
	else{
		/*Build the socket*/
		/*Sets the feilds in si_server*/
		bzero((char *) &si_server, sizeof(si_server));
		/*symbolic constant that gets the address AN-INET*/
		si_server.sin_family = AF_INET;
		bcopy((char *) server->h_addr,(char *) &si_server.sin_addr,server->h_length);
		si_server.sin_port = htons(SERVER_PORT);

		/* Open a socket*/
		/*domain, type, protocol */
		int sockfd =socket(PF_INET, SOCK_DGRAM, 0);
			if(sockfd <0)
				error("ERROR opening socket try later");
		/*USER Send data to server*/
			size_t lenserver=0;
	
	//int n= sendto(sockfd,&pack,sizeof(struct packet),0, (struct sockaddr *) &si_server,sizeof(si_server));
	while(1){	

			/*send*/
			 char *request[]="GET" . url . "HTTP/1.0\n Host:" . urlfirst . "\n User-Agent: Mozilla/5.0\n";
			
			int n= sendto(sockfd,&request,sizeof(struct packet),0, (struct sockaddr *) &si_server,sizeof(si_server));
			if (n<0){
				error("sendto");
				}
			/*receive*/
			char *ack; 
               		 int f = recvfrom(sockfd,&ack,1000000,0,(struct sockaddr*) &si_server,&addr_len);
}
