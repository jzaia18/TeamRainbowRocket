#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>

// All pokemon types
#define ELECTRIC_TYPENO 1
#define GRASS_TYPENO    2
#define POISON_TYPENO   3
#define FIRE_TYPENO     4
#define WATER_TYPENO    5
#define BUG_TYPENO      6
#define FLYING_TYPENO   7
#define NORMAL_TYPENO   8
#define GHOST_TYPENO    9
#define FIGHTING_TYPENO 10
#define ROCK_TYPENO     11
#define GROUND_TYPENO   12
#define PSYCHIC_TYPENO  13
#define DRAGON_TYPENO   14
#define DARK_TYPENO     15
#define ICE_TYPENO      16
#define STEEL_TYPENO    17
#define FAIRY_TYPENO    18

// All pokemon IDs
#define PIKACHU_IDNO     1
#define VENUSAUR_IDNO    2
#define CHARIZARD_IDNO   3
#define BLASTOISE_IDNO   4
#define AERODACTYL_IDNO  5
#define LAPRAS_IDNO      6
#define GENGAR_IDNO      7
#define MACHAMP_IDNO     8
#define MEWTWO_IDNO      9
#define SCYTHER_IDNO     10
#define SNORLAX_IDNO     11
#define DRAGONITE_IDNO   12


struct Move {
  char *name;
  char type; //of the move
  int power; //damage
  float acc; //accuracy, (0,1]
  char isphysical; char makescontact; char isheal; //treated as booleans
};

struct Pokemon {
  char* name;
  int maxhp; int currhp; int speed; int spatk; int atk; int spdef; int def; //stats
  char type1; char type2; //type(s) of the pokemon
  struct Move move1; struct Move move2; struct Move move3; struct Move move4; //moves

};

double randr(int a, int b) { // rand() but restricts nums [a,b]
  return a + (b-a+1) * rand()/((double) RAND_MAX); }
