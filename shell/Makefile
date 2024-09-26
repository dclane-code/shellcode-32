all:
	nasm -g -f elf32 -o shell.o shell.s
	ld -melf_i386 -o shell shell.o
	nasm -g -f bin -o shell.bin shell.s
	xxd -i shell.bin > shell.h
clean:
	rm shell.bin shell.o shell shell.h

