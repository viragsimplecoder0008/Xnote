CC = gcc
CFLAGS = -Wall -lncurses

OBJ = main.o file.o editor.o screen.o

xnote: $(OBJ)
	$(CC) -o xnote $(OBJ) -lncurses

%.o: %.c
	$(CC) -c $<

clean:
	rm -f *.o xnote
