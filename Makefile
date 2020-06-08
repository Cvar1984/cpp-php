COMPILE =g++
REMOVE =rm -rf
MOVE =mv
LIBDIR =${PREFIX}/lib/php
MAIN =main.cpp
OUTPUT =cvar1984.so
CFLAG +=-lphpcpp
CFLAG +=-I./include
CFLAG +=-shared
CFLAG +=-fpic
CFLAG +=-s
CFLAG +=-Wall

all:
	${COMPILE} ${MAIN} ${CFLAG} -o ${OUTPUT}
clean:
	${REMOVE} ${OUTPUT}
install:
	${MOVE} ${OUTPUT} ${LIBDIR}
uninstall:
	${REMOVE} ${LIBDIR}/${OUTPUT}
