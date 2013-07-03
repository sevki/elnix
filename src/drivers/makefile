CC=i586-elf-gcc
include ../cflags.mak

BUILD_DIR=./../build/

SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CCFLAGS)  -o $(BUILD_DIR)$@.o -c $<
