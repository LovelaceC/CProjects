CC=gcc
PKGCONF=pkg-config

FLAGS=-Wall -Werror -std=gnu99 -g
LIBS=`$(PKGCONF) --cflags --libs gtk+-3.0`

SOURCES=$(wildcard *.c)
OBJ=${SOURCES:.c=.o}

all: $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) $(LIBS) $< -o $@

clean:
	rm *.o
