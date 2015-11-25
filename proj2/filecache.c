#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int write_file(char *filename, char buffer[1000] );

char buffer[1000];

int write_file(char *filename, char buffer[1000]){
        FILE *file;
        int i;
        long size;
        int ret;

        file=fopen(filename, "w");
        fseek(file,0, SEEK_END);

        for(i=0; i<size; i++)
                if (file==(FILE*)NULL)
                 {
                        printf( "Could not open file\n" );
                        return 0;
               }
               while(i != 999)
                {
                        fprintf(file,"%s", buffer);
			if(ret<2)
                        {
                                fclose(file);
                                return;
                        }
                        if(i==999)
                        {
                                fclose(file);
                                return 1;
                        }

                        
                }
        fclose(file);
 }



