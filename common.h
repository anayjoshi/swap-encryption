#ifndef COMMON_H
#define COMMON_H

#define SUCCESS 0
#define FAILURE 1
#define BUFFER_SIZE 1024

void encrypt(char** data);
int read_buffer(int index, void** buffer, char* filename);
void flush_data(int index, int size, void* buffer, char* filename);

#endif
