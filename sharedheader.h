#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// All pokemon types
#define NORMAL_TYPENO   1
#define FIGHTING_TYPENO 2
#define FLYING_TYPENO   3
#define POISON_TYPENO   4
#define GROUND_TYPENO   5
#define ROCK_TYPENO     6
#define BUG_TYPENO      7
#define GHOST_TYPENO    8
#define STEEL_TYPENO    9
#define FIRE_TYPENO     10
#define WATER_TYPENO    11
#define GRASS_TYPENO    12
#define ELECTRIC_TYPENO 13
#define PSYCHIC_TYPENO  14
#define ICE_TYPENO      15
#define DRAGON_TYPENO   16
#define DARK_TYPENO     17
#define FAIRY_TYPENO    18

// All pokemon IDs
#define PIKACHU_IDNO     25
#define VENUSAUR_IDNO    3
#define CHARIZARD_IDNO   6
#define BLASTOISE_IDNO   9
#define AERODACTYL_IDNO  142
#define LAPRAS_IDNO      131
#define GENGAR_IDNO      94
#define MACHAMP_IDNO     68
#define MEWTWO_IDNO      150
#define SCYTHER_IDNO     123
#define SNORLAX_IDNO     143
#define DRAGONITE_IDNO   149

#define MAX_POKEMON_IDNO 721
#define MAX_MOVE_IDNO 722

#define POKEDATA_CSV "pokedata.csv"
#define MOVEDATA_CSV "moves.csv"


//======================= Typedefs =======================

struct Move {
  char *name; int id;
  char type; //of the move
  int power; //damage
  int pp;
  float acc; //accuracy, (0,1]
  int priority;
  char isphysical; char makescontact; char isheal; //treated as booleans
};

struct Pokemon {
  char* name; int id;
  int maxhp; int currhp; int speed; int spatk; int atk; int spdef; int def; //stats
  int accuracy; int evade; //extra stats (unused atm)
  char type1; char type2; //type(s) of the pokemon
  struct Move *move1; struct Move *move2; struct Move *move3; struct Move *move4; //moves
};


//======================= Versatile Functions =======================


// rand() but restricts nums [a,b]
static double randr(int a, int b) { //static is a slight cheat to get past the compiler here
  return a + (b-a+1) * rand()/((double) RAND_MAX); }

// converts type id into a readable string
static char *type_lookup(int typeid){ //static is a slight cheat to get past the compiler here
  switch(typeid) {
  case NORMAL_TYPENO:
    return "Normal";
  case FIGHTING_TYPENO:
    return "Fighting";
  case FLYING_TYPENO:
    return "Flying";
  case POISON_TYPENO:
    return "Poison";
  case GROUND_TYPENO:
    return "Ground";
  case ROCK_TYPENO:
    return "Rock";
  case BUG_TYPENO:
    return "Bug";
  case GHOST_TYPENO:
    return "Ghost";
  case STEEL_TYPENO:
    return "Steel";
  case FIRE_TYPENO:
    return "Fire";
  case WATER_TYPENO:
    return "Water";
  case GRASS_TYPENO:
    return "Grass";
  case ELECTRIC_TYPENO:
    return "Electric";
  case PSYCHIC_TYPENO:
    return "Psychic";
  case ICE_TYPENO:
    return "Ice";
  case DRAGON_TYPENO:
    return "Dragon";
  case DARK_TYPENO:
    return "Dark";
  case FAIRY_TYPENO:
    return "Fairy";
  }
  return "";
}

//======================= pokemon.c =======================

struct Pokemon *construct_pokemon(int id_num);
void print_pokemon_data(struct Pokemon *p);
void set_moves(struct Pokemon*p, int move_1, int move_2, int move_3, int move_4);
void print_move_data(struct Move *m);
void free_pokemon(struct Pokemon *p);
