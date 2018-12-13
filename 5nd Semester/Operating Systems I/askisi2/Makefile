CC=gcc
CFLAGS=-lpthread -Wall -Wextra
LDFLAGS=
SOURCES=server.c logariasmos.c sharedmemory.c sockets.c diafora.c client.c clientfunctions.c
OBJECTS= $(SOURCES:.c=.o)

all: client server

client:
	$(CC) $(CFLAGS) client.c clientfunctions.c -o client

server: 
	$(CC) $(CFLAGS) server.c logariasmos.c threads.c sockets.c diafora.c -o server
clean:
	rm -rf server client ParkingServer.socket
