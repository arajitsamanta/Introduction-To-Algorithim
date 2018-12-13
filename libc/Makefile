SHELL := /bin/sh
CC = gcc # C compiler
FLAGS =-std=gnu99 -Iinclude
CFLAGS = -fPIC -g# C flags
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command

TARGET = libcollection.so # target lib
SOURCES = $(wildcard src/*.c)
HEADERS = $(wildcard include/*.h)
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all
all: ${TARGET}

# -o $@ says, put the output of the compilation in the file named on the left side of the :
$(TARGET): $(HEADERS)
	$(CC) ${LDFLAGS} -o $@ $^

# the $< is the first item in the dependencies list, and the CFLAGS macro is defined as above
$(SOURCES:.c=.d):%.d:%.c
	$(CC) ${FLAGS} $(CFLAGS) -MM $< >$@
include $(SOURCES:.c=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET} ${OBJECTS} $(SOURCES:.c=.d)