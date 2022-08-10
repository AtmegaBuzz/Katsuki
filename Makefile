CC = gcc
SRC = src
PROG = katsuki
LIBS = `pkg-config --libs gtk+-3.0`
CFLAGS = `pkg-config --cflags gtk+-3.0`

all: katsuki

katsuki: ${SRC}/cscheme/colors.o ${SRC}/utils/utils.o ${SRC}/katsuki.o
	${CC} ${CFLAGS}  ${SRC}/cscheme/colors.o ${SRC}/utils/utils.o ${SRC}/katsuki.o  -o katsuki ${LIBS}

colors.o: ${SRC}/csheme/colors.c
		${CC} -c ${CFLAGS} colors.c ${LIBS}

utils.o: ${SRC}/utils/utils.c
		${CC} -c ${CFLAGS} utils.c ${LIBS}

katsuki.o: ${SRC}/katsuki.c
		${CC} -c ${CFLAGS} katsuki.c ${LIBS}

clean:
		rm ${SRC}/cscheme/colors.o
		rm ${SRC}/utils/utils.o 
		rm ${SRC}/main.o
		rm katsuki
		

# mygtkapp: main.c
# 		gcc `pkg-config --cflags gtk+-3.0` -o main main.c `pkg-config --libs gtk+-3.0`