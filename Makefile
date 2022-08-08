
CC = gcc
SRC = src
PROG = ${SRC}/main
LIBS = `pkg-config --libs gtk+-3.0`
CFLAGS = `pkg-config --cflags gtk+-3.0`


${PROG}: ${PROG}.c
		${CC} ${CFLAGS} -o ${PROG} ${PROG}.c ${LIBS}


clean:
		rm ${PROG}

# mygtkapp: main.c
# 		gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0`