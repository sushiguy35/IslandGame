build:
	gcc -o game ./src/*.c -lSDL2 

run:
	./game

clean:
	rm -rf game
