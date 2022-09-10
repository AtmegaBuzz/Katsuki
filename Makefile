CC = gcc
CLIENT = src/client
SERVER = src/server
PROG = katsuki
LIBS = `pkg-config --libs gtk+-3.0`
CFLAGS = `pkg-config --cflags gtk+-3.0`

all: katsuki server

katsuki: ${CLIENT}/utils.o ${CLIENT}/client.o ${CLIENT}/katsuki.o
	${CC} ${CFLAGS}  ${CLIENT}/utils.o ${CLIENT}/client.o ${CLIENT}/katsuki.o  -o katsuki ${LIBS}

client.o: ${CLIENT}/colors.c
		${CC} -c ${CFLAGS} client.c ${LIBS}

utils.o: ${CLIENT}/utils.c
		${CC} -c ${CFLAGS} utils.c ${LIBS}

katsuki.o: ${CLIENT}/katsuki.c
		${CC} -c ${CFLAGS} katsuki.c ${LIBS}


# server

server: ${SERVER}/queue.o ${SERVER}/server.o 
	${CC} ${SERVER}/queue.o ${SERVER}/server.o -o server

queue.o: ${SERVER}/queue.c
		${CC} -c queue.c

server.o: ${SERVER}/server.c
		${CC} -c server.c

clean:
		rm ${CLIENT}/client.o
		rm ${CLIENT}/utils.o 
		rm ${CLIENT}/katsuki.o
		rm katsuki
		
		rm ${SERVER}/queue.o
		rm ${SERVER}/server.o
		rm server