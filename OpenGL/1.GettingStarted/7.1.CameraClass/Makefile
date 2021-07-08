CC=gcc

FLAGS=-Werror -Iinc
LIBS=-lm -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

FILES=build/main.o build/lib/glad.o build/shader/shader.o build/camera/camera.o
OUT=bin/a.out

all: $(FILES)
	$(CC) $(FLAGS) $(FILES) -o $(OUT) $(LIBS)

build/main.o: src/main.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/lib/glad.o: src/lib/glad.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/shader/shader.o: src/shader/shader.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

build/camera/camera.o: src/camera/camera.c
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

run: all
	$(OUT)

clean:
	rm $(FILES)
	rm $(OUT)
