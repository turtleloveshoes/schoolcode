#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
#define SERVER_PORT 50009
#define BADCHECK 55
//The bad check is set to the character index of the first letter of the string for testing. The first packet should be corrupt. 
/*Client
 *  * Server hostname
 *   * file you want to transfer
 *    *
 *     * Client sends file to the server and the server saves it on the server
 *      * Client needs to map the host name of the server to the IP adress, built skt address DS, Create skt
 *       * then send buffer data
 *        * server then build the socket address
 *         * bind skt fo an address
 *          * recieve the data*/

/*Structsofwckaddr_in { 
	short sin_family;
	 * must be AF_INET 
	 u_short sin_port;
	 struct in_addr sin_addr;
	 char sin_zero[8];
	* Not used, must be zero 
	};
*/
struct packet{
	int checksum; 
	char msg;
	int packetnum;  
};
char STRING[50]="This is the packet string";

void main(int argc, char *argv[]){
  /*deal with sting*/
	int i=0;
	struct packet pack[25];
	printf("this is the strlen %d\n", strlen(STRING));

	while (strlen(STRING) != i ){
    		//pack[i]=(struct packet)malloc(sizeof(struct packet));		
		pack[i].msg=STRING[i];
		pack[i].checksum=STRING[i];
		pack[i].packetnum=i+1;
		if(pack[i].checksum==105){
			pack[i].checksum=55;
			}	
			printf("this is i:%d\n", i);
			printf("%d\n", pack[i].packetnum);
			printf("%c\n", pack[i].msg);
			printf("%d\n", pack[i].checksum);
			i++;
	}
		int packettotal=i;
	struct hostent *server;
	struct sockaddr_in si_server;	
        
		

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
		int j=0;
	int n= sendto(sockfd,&pack,sizeof(struct packet),0, (struct sockaddr *) &si_server,sizeof(si_server));
	while(1){	
		int seq=0;
		int win=5;
		int lastwin=0;
		while(j<= win){	
			int n= sendto(sockfd,&pack[j],sizeof(struct packet),0, (struct sockaddr *) &si_server,sizeof(si_server));
			if (n<0){
				error("sendto");
				}
			printf("packetsent\n");
			printf("%d\n", pack[j].packetnum);
			printf("%c\n", pack[j].msg);
			printf("%d\n", pack[j].checksum);
                      int addr_len = sizeof(si_server);
		/*receive the acknowledgement*/
		/*if ack number, then increment the seq num*/
		/*if ack is greater than the window*/
		struct packet ack; 
               		 int f = recvfrom(sockfd,&ack,1000000,0,(struct sockaddr*) &si_server,&addr_len);
                	printf("acknowlegement\n");
			printf("ack packet:%d\n", ack.packetnum);
			printf("ack msg: %c\n", ack.msg);
			printf("ack checksum%d\n", ack.checksum);
			//if received packet is corrupt ignore it
				if (ack.checksum==BADCHECK){
					printf("BAD CHECKSUM\n FROM PACKET SEQ # %d\n", ack.packetnum);
					//ignore packet 
				}
			//if acknowlegement is greater than window then slide window
				if (ack.packetnum > win){
					lastwin=win; 
					win=win+5;
				}
			//if reaches end of window and does not have all acknowlegements
				if(win==lastwin)
				{
					j=0;
				}
			//keep sending window
			j++;

			if (f<0){
                        	error("recvfrom");
		 		}
			}
	}
	}
}
