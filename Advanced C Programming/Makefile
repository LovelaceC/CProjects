CC=gcc

FLAGS=-Wall -Werror -O0 -g
PROGRAMS=1.AutoVariables.o 2.ExternVariables.o 3.StaticVariables.o \
	3.1.StaticFunctions.o 4.RegisterVariable.o 5.Challenge1.o \
	5.1.Challenge1.o 6.Define.o 8.VLA.o 8.1.Challenge.o \
	9.FlexibleArrayMembers.o 9.1.Challenge.o

all: $(PROGRAMS)
	@echo "Finished compiling all projects <333"

%.o :%.c
	@echo -e "CC\t\t" $<
	@$(CC) $(FLAGS) $< -o $@

clean:
	@echo "Cleaning programs"
	@rm $(PROGRAMS)
