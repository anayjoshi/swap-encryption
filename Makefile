CC=gcc
TARGET=swap

$(TARGET): main.o encrypt.o
	$(CC)  main.o encrypt.o -o $(TARGET)

main.o: main.c common.h
	$(CC) -c main.c -o main.o

encrypt.o: encrypt.c common.h
	$(CC) -c encrypt.c -o encrypt.o

clean: 
	rm *.o $(TARGET) 
