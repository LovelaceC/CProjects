CC=gcc

FLAGS=-Wall -Werror -O0 -g
PROGRAMS=1.AutoVariables.o 2.ExternVariables.o

all: $(PROGRAMS)
	echo "Finished compiling all projects <333"

%.o :%.c
	$(CC) $(FLAGS) $< -o $@

clean:
	rm $(PROGRAMS)
