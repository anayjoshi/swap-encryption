/*

a very simple tool to rearrange bits of every byte to 'encrypt' data

*/

#include<stdio.h>
#include<stdlib.h>
#include"common.h"


int main(int argc, char** argv) 
{
/*
we plan to encrypt data of the text file. First, open the file to be encrypted.
sanity check for possible errors
*/

	if(argc < 3 ) {
	fprintf(stderr,"not enough input file\n");
	exit(FAILURE);
	}

/*
read maximum of BUFFER_SIZE of data from the file into a buffer in main memory.
*/

	char* text_buffer = calloc(BUFFER_SIZE+1,sizeof(char));
	
	int cont = 1;
	int i = 0;
	int buffer_size = BUFFER_SIZE; //default buffer size
	while(cont)	{
	int s = read_buffer(i,&text_buffer,argv[1]);
		if(s < BUFFER_SIZE) {cont = 0; buffer_size = s; /*last block of data*/}
	encrypt(&text_buffer);
	flush_buffer(i,buffer_size,text_buffer,argv[2]);
	i++;
	}

return 0;
}
