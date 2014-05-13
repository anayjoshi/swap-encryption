/*


*/
#include<stdio.h>
#include<stdlib.h>
#include"common.h"

void encrypt(char** data) 
{
/* exchange upper nibble and lower nibble.*/
    int i = 0;
	for (i=0; i<BUFFER_SIZE; i++) 
    {
        (*data)[i] = (((*data)[i] & 0xf0) >> 4) | (((*data)[i] & 0x0f) << 4);
	}
}


void flush_buffer(int index, int size, void* buffer, char* filename) 
{


    FILE* doc = fopen(filename,"a+");
    if(doc == NULL) 
    {
        perror("flush_buffer: ");
        exit(FAILURE);
    }
    fseek(doc,(long)index*BUFFER_SIZE,SEEK_SET);
    fwrite(buffer,sizeof(char),size,doc);
    fclose(doc);
}


int read_buffer(int index, void** buffer, char* filename) 
{

    FILE* doc = fopen(filename,"r+");
    if(doc == NULL) 
    {
        perror("read_buffer: ");
        exit(FAILURE);
    }
    int offset = fseek(doc,(long)index*BUFFER_SIZE,SEEK_SET);
    int s = fread(*buffer,sizeof(char),BUFFER_SIZE,doc);
    fclose(doc);
    return s;
}
