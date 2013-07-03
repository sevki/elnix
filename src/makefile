CC=i586-elf-gcc
BUILD_DIR=./build/

TARGETS = boot libc drivers kernel

OBJS=$(wildcard build/*.o)

all: compile link

.PHONY: compile
compile:$(TARGETS)
	for target in $(TARGETS); do \
		echo [Compiling $$target] ; \
		$(MAKE) -C $$target; \
	done

link: $(TARGETS)
	echo [Linking $(OBJS)] ;
	$(CC) -T linker.ld -o release/elnix.bin -ffreestanding -O2 -nostdlib $(OBJS) -lgcc