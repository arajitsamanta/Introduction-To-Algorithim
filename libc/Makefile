CC = gcc # C compiler
SOURCE = $(wildcard src/*.c)
OBJECTS = $(SOURCE:.c=.o)
DEPS = $(OBJECTS:.o=.d)  # one dependency file for each source
LDFLAGS = -shared
CFLAGS = -fPIC -Wall -Wextra -Iinclude

# Generate .so for linux and .dll for windows. Not support MacOS for now.
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

# Rule to generate a dep file by using the C preprocessor
%.d: %.c
	$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(OBJECTS) ${TARGET} $(DEPS)