#include "sharedheader.h"

// I have decided to write my own csv functions, the ones I found online did not work well for our purposes.
// Extracts one comma-separated line from the csv
char *get_poke_entry(int num) {
  int fd = open(POKEDATA_CSV, O_RDONLY);
  if (num < 1 || num > MAX_POKEMON_IDNO)
    return "";

  // read the file in (exact size)
  struct stat ap;
  stat(POKEDATA_CSV, &ap);
  char buf[ap.st_size+15];
  read(fd, buf, sizeof(buf));

  // Skip the 1st line (header line)
  strtok(buf, "\n");

  char i = num - 1;
  while (i-- > 0) strtok(NULL, "\n"); // Run down the entries in the list
  return strtok(NULL, "\n"); // Return the correct entry
}

// Plugs numbers in to the pokemon stat formula
int stat_formula(int base, int ev, int iv, int level) {
  return (2 * base + iv + ev/4 ) * level / 100 +5;
}

// Sets all the stats of a Pokemon (ONLY FOR USE AS A HELPER FUNCTION, this will break if not called in the right place.)
void set_stats(struct Pokemon* p) {
  int ev = 0; //for future use
  int iv = 0; //same
  int level = 50; //saaaaame

  //hp is special
  p->maxhp = (2 * atoi(strtok(NULL, ",")) + iv + ev/4) * level / 100 + level + 10;
  p->currhp = p->maxhp;

  //other stats all use the same formula
  p->atk = stat_formula( atoi(strtok(NULL, ",")), ev, iv, level);
  p->def = stat_formula( atoi(strtok(NULL, ",")), ev, iv, level);
  p->spatk = stat_formula( atoi(strtok(NULL, ",")), ev, iv, level);
  p->spdef = stat_formula( atoi(strtok(NULL, ",")), ev, iv, level);
  p->speed = stat_formula( atoi(strtok(NULL, ",")), ev, iv, level);

  //unused
  p->accuracy = 0;
  p->evade = 0;
}

// Constructs a pokemon by using data from the csv
struct Pokemon *construct_pokemon(int id_num) {
  struct Pokemon *p = malloc(sizeof(struct Pokemon)); //no need for default zeros

  char *data = get_poke_entry(id_num); //grab comma separated data

  // the following must be executed IN THIS ORDER
  p->id=atoi(strtok(data, ","));
  p->name=strtok(NULL, ",");
  p->type1=atoi(strtok(NULL, ","));
  p->type2=atoi(strtok(NULL, ","));
  set_stats(p); //DO NOT USE OUTSIDE OF THIS FUNCTION
  setMoves(p, 1, 2, 3, 4);
  return p;
}

// Print out all information of a given pokemon for easy viewing
void print_pokemon_data(struct Pokemon *p) {
  printf("Printing the information for this %s (#%d):\n", p->name, p->id);
  printf("Type: %s %s\n", type_lookup(p->type1), type_lookup(p->type2));
  printf("Stats:\n");
  printf("  %d/%d HP\n", p->currhp, p->maxhp);
  printf("  atk: %d\t", p->atk);
  printf("  def: %d\t", p->def);
  printf("  spatk: %d\t", p->spatk);
  printf("  spdef: %d\t", p->spdef);
  printf("  speed: %d\n", p->speed);
  printf("  Moves:\n\t%s\t\t%s\n%s\t%s\n", p->move1->name, p->move2->name, p->move3->name, p->move4->name);
}

//TODO

char *get_move_entry(int num) {
    int fd = open(MOVEDATA_CSV, O_RDONLY);
    if (num < 1 || num > MAX_MOVE_IDNO)
        return "";
    
    // read the file in (exact size)
    struct stat ap;
    stat(MOVEDATA_CSV, &ap);
    char buf[ap.st_size+15];
    read(fd, buf, sizeof(buf));
    
    // Skip the 1st line (header line)
    strtok(buf, "\n");
    
    char i = num - 1;
    while (i-- > 0) strtok(NULL, "\n"); // Run down the entries in the list
    return strtok(NULL, "\n"); // Return the correct entry
}

struct Move *construct_move(int MOVE_ID){
  struct Move *m = malloc(sizeof(struct Move));

  char *data = get_move_entry(MOVE_ID); //grabs data for the move

  m->id = atoi(strtok(data, ","));
  m->name = strtok(NULL, ",");
  m->type = atoi(strtok(NULL, ","));
  m->power = atoi(strtok(NULL, ","));
  m->pp = atoi(strtok(NULL, ","));
  m->acc = atoi(strtok(NULL, ","));
  m->priority = atoi(strtok(NULL, ","));

    //still needs more stuffs

  return m;
}
void setMoves(struct Pokemon *p, int MOVE_1, int MOVE_2, int MOVE_3, int MOVE_4){
  struct Move *MOVE1 = construct_move(MOVE_1);
  struct Move *MOVE2 = construct_move(MOVE_2);
  struct Move *MOVE3 = construct_move(MOVE_3);
  struct Move *MOVE4 = construct_move(MOVE_4);

  p->move1 = MOVE1;
  p->move2 = MOVE2;
  p->move3 = MOVE3;
  p->move4 = MOVE4;
    
}
void printmovedata(struct Move *m){
  printf("Printing the information for the move %s\n", m->name);
  printf("\tid: %d\n", m->id);
  printf("\tname: %s\n", m->name);
  printf("\ttype: %s\n", type_lookup(m->type));
  printf("\tpower: %d\n", m->power);
  printf("\taccuracy: %f\n", m->acc);
  printf("\tpriority: %d\n", m->priority);
}

// This main is a test, this file is NOT the main file
int main() {
  struct Pokemon *pikachu = construct_pokemon(PIKACHU_IDNO);
  print_pokemon_data(pikachu);

  printmovedata(pikachu->move1);
  printmovedata(pikachu->move2);
  printmovedata(pikachu->move3);
  printmovedata(pikachu->move4);
}

