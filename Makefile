CC = gcc
SRC = src
PROG = ${SRC}/main
LIBS = `pkg-config --libs gtk+-3.0`
CFLAGS = `pkg-config --cflags gtk+-3.0`

all: katsuki

katsuki: ${SRC}/csheme/colors.o ${SRC}/utils/utils.o ${SRC}/main.o
	gcc -c -Wall katsuki colors.o utils.o main.o

colors.o: ${SRC}/csheme/colors.c
		${CC} -c ${CFLAGS} colors.c ${LIBS}

utils.o: ${SRC}/utils/utils.c
		${CC} -c ${CFLAGS} utils.c ${LIBS}

main.o: ${SRC}/main.c
		${CC} -c ${CFLAGS} main.c ${LIBS}

# clean:
# 		rm ${PROG}

# mygtkapp: main.c
# 		gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0`