run: all
	./pokemonCup

run2: client server

all: pokemon.o main.o battleutils.o teambuildering.o
	gcc -g -o pokemonCup main.o pokemon.o battleutils.o teambuildering.o

all2: pokemon.o main.o battleutils.o teambuildering.o networking.o client.o server.o
	gcc -g -o pokemonCup main.o pokemon.o battleutils.o teambuildering.o networking.o client.o server.o

client: pokemon.o battleutils.o teambuildering.o networking.o client.o main.o
	gcc -g -o client pokemon.o battleutils.o teambuildering.o networking.o client.o main.o

server: pokemon.o battleutils.o teambuildering.o networking.o server.o main.o
	gcc -g -o server pokemon.o battleutils.o teambuildering.o networking.o server.o main.o

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

teambuildering.o: teambuildering.c
	gcc -g -c teambuildering.c

battleutils.o: battleutils.c
	gcc -g -c battleutils.c

networking.o: networking.c
	gcc -g -c networking.c

client.o: client.c
	gcc -g -c client.c

server.o: server.c
	gcc -g -c server.c

clean:
	rm *.o
	rm pokemonCup

valgrind: recompile
	valgrind --leak-check=full ./pokemonCup

gdb: recompile
	gdb ./pokemonCup
