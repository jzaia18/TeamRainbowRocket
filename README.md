# TeamRainbowRocket
Project 2: The final frontier

by Leo Liu, Piotr Milewski, Jake Zaia & Rihui Zheng

## What it is
This project is a pokemon battle simulator where users can choose a pokemon, set its moves and prepare for battle. Then they can choose to face off, either against an AI, or against other users using networking. The mechanics and formulas used are all taken from the real pokemon games (as of 3 years ago).

## How it works


## Files

### battleutils.c
This file contains the formulas used for calculating damage when pokemon are battling. It is in escence a giant list of operations.

### client.c

### main.c
This file is the one that contains the main method that interacts with all other files. It contains few functions of its own.

### networking.c

### pokemon.c
Contains helper files for creating pokemon and moves and setting this attributes.

### server.c

### teambuildering.c
Contains teambuilding functions. This is effectively a wrapper for pokemon.c that uses its methods for higher level purposes.
