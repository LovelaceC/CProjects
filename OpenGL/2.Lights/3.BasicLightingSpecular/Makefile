CC=gcc

FLAGS=-Werror -Iinc -I../../inc -O0 -g
LIBS=-lm -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

FILES=build/main.o build/lib/glad.o ../../inc/shader.o ../../inc/camera.o
OUT=bin/a.out

all: $(FILES)
	$(CC) $(FLAGS) $(FILES) -o $(OUT) $(LIBS)

build/main.o: src/main.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/lib/glad.o: src/lib/glad.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

../../inc/shader.o: ../../inc/shader.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

../../inc/camera.o: ../../inc/camera.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

run: all
	$(OUT)

clean:
	rm $(FILES)
	rm $(OUT)
