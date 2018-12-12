SHELL = /bin/sh
CC    = gcc
#FLAGS       = -std=gnu99 -Iinclude
CFLAGS       = -fPIC -Wall -Wextra #-pedantic -march=native -ggdb3
LDLFLAGS=	 = -shared
DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

TARGET_LIB  = example.so
SOURCES = $(wildcard src/*.c)
HEADERS = $(wildcard include/*.h)
OBJECTS = $(SOURCES:.c=.o)

PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin

.PHONY: all
all: ${TARGET_LIB}

# -o $@ says, put the output of the compilation in the file named on the left side of the :
$(TARGET_LIB): $(HEADERS)
	$(CC) ${LDFLAGS} -o $@ $^

# the $< is the first item in the dependencies list, and the CFLAGS macro is defined as above
$(SOURCES:.c=.o):%.o:%.c
	$(CC) $(CFLAGS) -MM $< >$@
include $(SOURCES:.c=.o)


#$(TARGET_LIB): $(OBJECTS)
#	$(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(OBJECTS)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJECTS} $(SOURCES:.c=.o)