LIB_DIR =$(shell php-config --extension-dir)
PREFIX =$(shell php-config --prefix)
INCLUDE_DIR =./include
MAIN =main.cpp
OUTPUT =cvar1984.so
LIB_DIR_OP = ${LIB_DIR}/${OUTPUT}
CFLAG +=-lphpcpp
CFLAG +=-I${INCLUDE_DIR}
CFLAG +=-shared
CFLAG +=-fpic
CFLAG +=-s
CFLAG +=-Wall
CFLAG +=-o
COMPILE =g++
REMOVE =rm -rf
MOVE =mv

all:
	${COMPILE} ${MAIN} ${CFLAG} ${OUTPUT}
clean:
	${REMOVE} ${OUTPUT}
install:
	${MOVE} ${OUTPUT} ${LIB_DIR}
uninstall:
	${REMOVE} ${LIB_DIR_OP}
