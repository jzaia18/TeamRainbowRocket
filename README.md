# TeamRainbowRocket
Project 2: The final frontier

by Leo Liu, Piotr Milewski, Jake Zaia & Rihui Zheng

## What it is
This project is a pokemon battle simulator where users can choose a pokemon, set its moves and prepare for battle. Then players face off against other users using networking. The mechanics and formulas used are all taken from the real pokemon games (as of 3 years ago).

## How it works
Pokemon and Moves are both structs that get their contents from a large CSV of all pokemon data. Pokemon can be turned into strings and back into Pokemon, which is how the server and clients easily communicate.

## Files

### battleutils.c
This file contains the formulas used for calculating damage when pokemon are battling. It is in escence a giant list of operations.

### client.c
Contains a majority of the code for displaying information to the user and taking input.

#### main.c (merged into client.c)
This file is the one that contains the main method that interacts with all other files. It contains few functions of its own.

### networking.c
Contains utilities for client to server communications.

### pokemon.c
Contains helper files for creating pokemon and moves and setting this attributes.

### server.c
Sets up a server that will facilitate client connections for multiplayer battling.

### teambuildering.c
Contains teambuilding functions. This is effectively a wrapper for pokemon.c that uses its methods for higher level purposes.
