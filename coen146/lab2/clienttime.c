#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<sys/times.h>
#define SERVER_PORT 50009
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
	static clock_t st_time; 
	static clock_t en_time; 
	static struct tms st_cpu;
	static struct tms en_cpu; 
void start_clock(){
	st_time=times(&st_cpu);
}
void end_clock(){
 int i;
 for(i=0;i<100000000;i++);
	en_time=times(&en_cpu);
//	fputs(msg, stdout);
	printf("\nRealTime:%jd\n, User Time: %jd, System Time:%jd\n", (intmax_t)(en_time-st_time), (intmax_t)(en_cpu.tms_utime-st_cpu.tms_utime), (intmax_t)(en_cpu.tms_stime- st_cpu.tms_stime));
	printf("\n difftime %jd", difftime(en_time, st_time));
}


void main(int argc, char *argv[]){
  /*deal with file*/
	FILE *fp;
    	char *red;  
	struct hostent *server;
	struct sockaddr_in si_server;	
	double totaltime; 
	
	//times((struct tms)*red);
	
	start_clock();
	if( (fp=fopen(argv[2],"r"))== NULL)
	  {
	    error("file is NULL ");
	  }

	    fseek(fp, 0, SEEK_END);
		long pos=ftell(fp);
		fseek(fp, 0, SEEK_SET);
		
		red =(char *)malloc(sizeof(char)*pos);		
		//printf("dump/n");
		fread(red, pos, 1, fp);
	//printf(red);	  
	fclose(fp);

	/*deal with server*/
	server=gethostbyname(argv[1]);
	/*Make sure the server is there*/
	if (server == NULL){
		fprintf(stderr,"ERROR, no such host");
		exit(0);
	}
	else{
		/*Timer start*/
		//start=clock();
		//for(x=0; x<10000; x++)
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
			//int redlen=strlen(*red);
		int n= sendto(sockfd,red,strlen(red),0, (struct sockaddr *) &si_server,sizeof(si_server));
		if (n<0)
			error("sendto");
		
	end_clock();
		}
}
