
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
}
