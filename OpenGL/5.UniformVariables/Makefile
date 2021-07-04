CC=gcc

FLAGS=-Wall -Werror -std=gnu99 -I..
LIBS=-lm -lGL -lglut -lX11 -lGLEW

OUT=a.out

FILES=build/main.o
LIB_FILES=../lib/math.o ../lib/util.o

all: $(FILES)
	$(CC) $(FLAGS) $(FILES) $(LIB_FILES) -o $(OUT) $(LIBS)

build/main.o: src/main.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

run:
	$(OUT)

clean:
	rm $(FILES)
	rm $(OUT)
