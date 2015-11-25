#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
#define SERVER_PORT 50009
struct packet{
	int packetnum;
	char msg;
	int checksum;

};
int main(){
	printf("recieve/n");

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


while(1){

  /*SERVER Receive from client*/
                /*filedescriptor, bufferreadby, max bytes, flags, pointer to cockaddr, size*/
	//	
			int flag=0;
               		int n = recvfrom(sockfd,packet2,sizeof(struct packet),0,(struct sockaddr*) &si_server,&addr_len);
			if (n<0){
                       	 error("recvfrom");
			}
                	printf("Packet Number received:%d\n", packet2.packetnum);
		//	if(packet2.msg != packet2.checksum){
		//		flag=1;
		//	}
			/*say something if it was corrupt*/
			//if (flag==1){
                        //	error("recvfrom");
			//	printf("packet %d was corrupt", j);
			//}
			/*this is the acknowlegement*/
			printf("packetnumber: %c\n message: %d\n packetchecksum: %d\n", packet2.packetnum, packet2.msg, packet2.checksum);
			struct packet ack;
			/*copy packet to acknowledgement*/
			ack.packetnum=packet2.packetnum;	
			strcpy(packet2.msg,ack.msg);
			toupper(ack.msg);
			ack.checksum=packet2.checksum;
		
			/*send */
			int f= sendto(sockfd,&ack,sizeof(ack),0, (struct sockaddr *) &si_server,sizeof(si_server));
			if (f<0){
				error("sendto");
				}
			j++;
               
	}
}
