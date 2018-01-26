run: all
	./server

all: client server

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
	rm server client pokemonCup

valgrind: recompile
	valgrind --leak-check=full ./pokemonCup

gdb: recompile
	gdb ./pokemonCup
