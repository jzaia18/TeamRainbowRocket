run: all
	./pokemonCup

all: pokemon.o main.o battleutils.o client.o
	gcc -g -o pokemonCup main.o pokemon.o battleutils.o client.o

serversetup: server.o
	gcc -o server server.o

rerun: recompile
	./pokemonCup

recompile: all
	rm *.o

pokemon.o: main.o
	gcc -g -c pokemon.c

main.o: main.c
	gcc -g -c main.c

battleutils.o: battleutils.c
	gcc -g -c battleutils.c

client.o: client.c
	gcc -c client.c

server.o: server.c
	gcc -c server.c

clean:
	rm *.o
	rm pokemonCup

valgrind: recompile
	valgrind --leak-check=full ./pokemonCup

gdb: recompile
	gdb ./pokemonCup
