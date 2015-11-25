#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define SERVER_PORT 50009
#define BADCHECK 55
struct packet{
	int checksum;
	char msg;
	int packetnum;

};
int main(){

struct sockaddr_in si_server;

socklen_t addr_len;

int lengthofhost;

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
	if(bind(sockfd, (struct sockaddr *) &si_server, sizeof(si_server))<0){
		error("ERROR on binding");
	}
	lengthofhost=sizeof(si_server);
	printf("recieve/n");
	struct packet packet2;
	int i=0;
	int j=0;
/*which number it is requesting*/
int request=0;
/*what sequence number you are on*/
int seq=1;


/*window size*/
int win=5;
while(1){

  /*SERVER Receive from client*/
                /*filedescriptor, bufferreadby, max bytes, flags, pointer to cockaddr, size*/
	
			int flag=0;

  //if the sequence number is between the window it is accepted  and there are no errors
  //put it in the array 
  //increment the request number 
  //send acknowlegement and next sequence number 
            		
			int n = recvfrom(sockfd,&packet2,sizeof(struct packet),0,(struct sockaddr*) &si_server,&addr_len);
			if (n<0){
                       	 error("recvfrom");
			}
			if (packet2.checksum==BADCHECK){
				printf("BADCHECKSUM! IGNORE!\n PACKET NUMBER:%d\n", packet2.checksum );
			}
			if(packet2.checksum!=BADCHECK && packet2.packetnum <= win)
			{
			 	j++;
				printf("Receiving...Packet number:%d\n", packet2.packetnum);
				/*this is the acknowlegement*/
				printf("packetnumber: %d\n message: %c\n packetchecksum: %d\n", packet2.packetnum, packet2.msg, packet2.checksum);
					/*Create packet acknowlegement*/
			struct packet ack;
			/*copy packet to acknowledgement where sequ num becomes request number*/
			ack.packetnum=packet2.packetnum+1;	
			ack.msg=packet2.msg;
			ack.checksum=packet2.checksum;
		
			/*send */
			int f= sendto(sockfd,&ack,sizeof(struct packet),0, (struct sockaddr *) &si_server,sizeof(si_server));
		
			/*print if send function errors*/		
			if (f<0){
                           	 printf("Problem\n");
				error("sendto");
				}
			j++;

			}	
			if(packet2.packetnum>win){
				win=win+5;
			}
		
	}
}

