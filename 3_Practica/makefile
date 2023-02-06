CC = gcc
CFLAGS = -Wall -Werror
OUTPUT = Cliente.o
DEBUG =  -g
SOURCES = Cliente.c

all:
	$(CC) $(SOURCES) $(CFLAGS) -o $(OUTPUT)
debug:
	$(CC) $(SOURCES) $(CFLAGS) -o $(OUTPUT) 
clean:
	rm -f $(OUTPUT)
fresh:
	make clean
	make all
