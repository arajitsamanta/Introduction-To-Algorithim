CC = gcc # C compiler
SOURCE = $(wildcard src/*.c)
HEADERS = $(wildcard include/*.h)
OBJECTS = $(SOURCE:.c=.o)
DEPS = $(OBJECTS:.o=.d)  # one dependency file for each source

LDFLAGS = -shared
CFLAGS = -fPIC -Wall -Wextra -Iinclude

# GEnerate so foe linux and dll for windows. Not support MacOS for now.
ifeq ($(shell uname -s), Linux)
  TARGET = libcollection.so
else
  TARGET = libcollection.dll
endif

.PHONY: all
	all: ${TARGET}

${TARGET}: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

include $(DEPS)   # include all dependencies files in the makefile

# rule to generate a dep file by using the C preprocessor
%.d: %.c
	$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(OBJECTS) ${TARGET} $(DEPS)