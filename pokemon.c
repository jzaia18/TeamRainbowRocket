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
  char file[ap.st_size+15];
  read(fd, file, sizeof(file));

  // Skip the 1st line (header line)
  char *buf = file;
  strsep(&buf, "\n");
  close(fd);

  int i = num - 1;
  while (i-- > 0) strsep(&buf, "\n"); // Run down the entries in the list

  char *ret = strcpy(malloc(1000), strsep(&buf, "\n"));
  return ret; // Return the correct entry
}

// Plugs numbers in to the pokemon stat formula
int stat_formula(int base, int ev, int iv, int level) {
  return (2 * base + iv + ev/4 ) * level / 100 +5;
}

// Sets all the stats of a Pokemon (ONLY FOR USE AS A HELPER FUNCTION, this will break if not called in the right place.)
void set_stats(struct Pokemon* p, char *data) {
  int ev = 0; //for future use
  int iv = 0; //same
  int level = 50; //saaaaame

  //hp is special
  p->maxhp = (2 * atoi(strsep(&data, ",")) + iv + ev/4) * level / 100 + level + 10;
  p->currhp = p->maxhp;

  //other stats all use the same formula
  p->atk = stat_formula(atoi(strsep(&data, ",")), ev, iv, level);
  p->def = stat_formula(atoi(strsep(&data, ",")), ev, iv, level);
  p->spatk = stat_formula(atoi(strsep(&data, ",")), ev, iv, level);
  p->spdef = stat_formula(atoi(strsep(&data, ",")), ev, iv, level);
  p->speed = stat_formula(atoi(strsep(&data, ",")), ev, iv, level);

  //unused
  p->accuracy = 0;
  p->evade = 0;
}

// Constructs a pokemon by using data from the csv
struct Pokemon *construct_pokemon(int id_num, int m1, int m2, int m3, int m4) {
  if (id_num < 1 || id_num > MAX_POKEMON_IDNO)
    return NULL;

  struct Pokemon *p = malloc(sizeof(struct Pokemon)); //no need for default zeros

  char *to_free = get_poke_entry(id_num); //grab comma separated data
  char *data = to_free;

  // the following must be executed IN THIS ORDER
  p->id=atoi(strsep(&data, ","));
  p->name=strcpy(malloc(50), strsep(&data, ","));
  p->type1=atoi(strsep(&data, ","));
  p->type2=atoi(strsep(&data, ","));
  set_stats(p, data);
  set_moves(p, m1, m2, m3, m4);

  free(to_free);

  return p;
}

// Print out all information of a given pokemon for easy viewing
void print_pokemon_data(struct Pokemon *p) {
  if (!p)
    return;

  printf("Printing the information for this %s (#%d):\n", p->name, p->id);
  printf("Type: %s %s\n", type_lookup(p->type1), type_lookup(p->type2));
  printf("Stats:\n");
  printf("  %d/%d HP\n", p->currhp, p->maxhp);
  printf("  atk: %d\t", p->atk);
  printf("  def: %d\t", p->def);
  printf("  spatk: %d\t", p->spatk);
  printf("  spdef: %d\t", p->spdef);
  printf("  speed: %d\n", p->speed);
  printf("  Moves:\n\t1) %s\t2) %s\n\t3) %s\t4) %s\n", p->move1->name, p->move2->name, p->move3->name, p->move4->name);
}

// Returns 1 line from the moves csv
char *get_move_entry(int num) {
  int fd = open(MOVEDATA_CSV, O_RDONLY);
  if (num < 1 || num > MAX_MOVE_IDNO)
    return "";

  // read the file in (exact size)
  struct stat ap;
  stat(MOVEDATA_CSV, &ap);
  char file[ap.st_size+15];
  read(fd, file, sizeof(file));

  // Skip the 1st line (header line)
  //strtok(buf, "\n");

  char *buf = file;

  strsep(&buf, "\n");
  close(fd);
  int i = num - 1;
  while (i-- > 0) strsep(&buf, "\n"); // Run down the entries in the list

  char *ret = strcpy(malloc(1000), strsep(&buf, "\n"));
  return ret; // Return the correct entry
}

// Constructs and mallocs a struct Move
struct Move *construct_move(int move_id){
  if (move_id >= FIRST_ZMOVE_ID) {
    if (move_id <= LAST_ZMOVE_ID)
      return NULL;
    else
      move_id -= LAST_ZMOVE_ID - FIRST_ZMOVE_ID + 1;
  }

  if (move_id > MAX_MOVE_IDNO || move_id < 1)
    return NULL;

  struct Move *m = malloc(sizeof(struct Move));

  char *to_free = get_move_entry(move_id); //grabs data for the move
  char *data = to_free;

  m->id = atoi(strsep(&data, ","));
  m->name = strcpy(malloc(50),strsep(&data, ","));
  m->type = atoi(strsep(&data, ","));
  m->power = atoi(strsep(&data, ","));
  m->pp = atoi(strsep(&data, ","));
  m->acc = atoi(strsep(&data, ","));
  m->priority = atoi(strsep(&data, ","));
  //still needs more stuffs

  free(to_free);
  return m;
}

// sets the 4 moves of a struct Pokemon
void set_moves(struct Pokemon *p, int move_1, int move_2, int move_3, int move_4){
  struct Move *move1 = construct_move(move_1);
  struct Move *move2 = construct_move(move_2);
  struct Move *move3 = construct_move(move_3);
  struct Move *move4 = construct_move(move_4);

  p->move1 = move1;
  p->move2 = move2;
  p->move3 = move3;
  p->move4 = move4;
}

// Prints contents of a struct Move
void print_move_data(struct Move *m){
  printf("Printing the information for the move %s\n", m->name);
  printf("\tid: %d\n", m->id);
  printf("\tname: %s\n", m->name);
  printf("\ttype: %s\n", type_lookup(m->type));
  printf("\tpower: %d\n", m->power);
  printf("\taccuracy: %f\n", m->acc);
  printf("\tpriority: %d\n", m->priority);
}

// frees a move
void free_move(struct Move* m) {
  free(m->name);
  free(m);
}

// Frees a pokemon and its moves
void free_pokemon(struct Pokemon* p) {
  free(p->name);
  free_move(p->move1);
  free_move(p->move2);
  free_move(p->move3);
  free_move(p->move4);
  free(p);
}

/*
// This main is a test, this file is NOT the main file
int main() {

  //int i = 5;
  //  while (--i){
  struct Pokemon *pikachu = construct_pokemon(PIKACHU_IDNO);
  print_pokemon_data(pikachu);

  //struct Pokemon *mewTOO = construct_pokemon(MEWTWO_IDNO);
  //printf("mewtwo id: %d\n", MEWTWO_IDNO);
  //print_pokemon_data(mewTOO);

  print_move_data(pikachu->move1);

  free_pokemon(pikachu);
}
*/
