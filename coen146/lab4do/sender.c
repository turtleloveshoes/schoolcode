#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
#define SERVER_PORT 50009
#define SWS /*size of slidding window*/
#define RWS /*buffer file? */
/*sliding window protocol*/
typedef u_char SwpSeqno;

typedef struct {
	SwpSeqno SeqNum; /*sequence num*/
	SwpSeqno AckNum; /*acknowledgement of received frame from reciever*/
	u_char Flags;/*flags*/
} swpHdr;

/*sender*/

typedef struct {
	Swp lastawk; /*last num ack*/
	Swp lastfrm /*last frame sent*/
	Semaphore sendWindowNotFull;
	SwpHdr hdr; /*preinitialized header*/
	
	struct sendQ_slot {
		Event: timeout; /*event associated with send */
		Msg msg;
	} sendQ[SWS];

	/* reciever side state*/
	SwpSeqno nextframe; /*seq next frame*/
	
	struct recvQ_slot {
	int recieved; 
	Msg msg;
	} recvQ[RWS];
}SwpState;




static int
sendSWP(SwpState *state, Msg *frame)
{
	struct sendQ_slot *slot; 
	hbuf[HLEN];

	/*wait for second window*/
	semWait(&state->sendWindowNotFull);
	state->hdr.Seqnum =++state->lastfrm;
	slot=&state->sendQ[state->hdr.SeqNum % SWS];
	store_swp_hdr(state->hdr, hbuf);
	msgAddHdr(frame, hdr, HLEN);
	msgSaveCopy(&slot->msg, frame);
	slot->timeout =evSchedule(swpTimeout, slot, SWP_SEND_TIMEOUT);
	return send(LINK, frame);
}

static int
deliverSWP(SwpState state, Msg *frame){
	SwpHdr hdr;
	char *hbuf;
	
	hbuf= msgStripHdr(frame, HLEN);
	load_swp_hdr(&hdr, hbuf);
	if (hdr->Flags & FLAG_ACK_VALID)
	{
		/*recieved an acknowledgement--do sender*/
		if(swpInWindow(hdr.AckNum. state->lastawk+1, state->lastfrm)){
		
			do{
				struct sendQ_slot *slot;
			
				slot=&state->sendQ[++state->lastawk %SWS];
				evCancel(slot->timeout);
				msgDestroy(&slot->msg);
				semSignal(&state->sendWindowNotFull);
			}while(state->lastawk !=hdr.AckNum)
	
		}
	}
	
	if(hdr.Flags & FLAG_HAS_DATA)
	{
		struct recvQ_slot *slot;
	/*recieved do Reciever*/
	slot=&state->recvQ[hdr.SeqNum % RWS];
	if (!swpInWindow(hdr.Seqnum, state->nextframe, state->nextframe+RWS-1)){
		return SUCESS; 
	}
	msgSaveCopy(&slot->msg, frame);
	slot->received =TRUE;
		if(hdr.SeqNum ==state->nextframe)
		{
			Msg m; 
			
			while(slot->recieved)
			{
				deliver(HLP, &slot->msg);
				msgDestroy(&slot->msg);
				slot->received=FALSE; 
				slot=&state->recvQ[++state->nextframe %RWS];
			}
			/*send ack*/
			prepare_ack(&m, state->nextframe-1)
			send(LINK, &m);
			msgDestroy(&m);
		}
	}
	return SUCESS; 
}

static bool
swpInWindow(SwpSeqno seqno, SwpSeqno min, SwpSeqno max){
	SwpSeqno pos, maxpos;
	pos =seqno-min;
	maxpos=max-min+1;
	return pos<maxpos;
}

void main(int argc, char *argv[]){
  /*deal with file*/
	FILE *fp;
    char *red;  
	struct hostent *server;
	struct sockaddr_in si_server;	

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
		
	}
}
