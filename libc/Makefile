SHELL := /bin/sh
CC = gcc # C compiler
FLAGS =-Iinclude
CFLAGS = -g3 -Wall -Wextra -fPIC
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command

TARGET = cyglibcollection.dll # target lib
TARGET_STATIC = libcollection.a # target lib
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
	$(CC) $(FLAGS) $(CFLAGS) -MM $< >$@
include $(SOURCES:.c=.d)

#$(TARGET):$(OBJECTS)
#	$(CC) $(FLAGS) $(CFLAGS) ${LDFLAGS} $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS)

.PHONY: clean
clean:
	-${RM} ${TARGET} ${OBJECTS} $(SOURCES:.c=.d)
