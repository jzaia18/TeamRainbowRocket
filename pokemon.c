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
  //strtok(buf, "\n");

  char *buf = file;
  strsep(&buf, "\n");
  close(fd);
  int i = num - 1;
  while (i-- > 0) strsep(&buf, "\n"); // Run down the entries in the list
  return strsep(&buf, "\n"); // Return the correct entry
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
struct Pokemon *construct_pokemon(int id_num) {
  struct Pokemon *p = malloc(sizeof(struct Pokemon)); //no need for default zeros

  char *data = get_poke_entry(id_num); //grab comma separated data

  // the following must be executed IN THIS ORDER
  p->id=atoi(strsep(&data, ","));
  p->name=strcpy(malloc(50), strsep(&data, ","));
  p->type1=atoi(strsep(&data, ","));
  p->type2=atoi(strsep(&data, ","));
  set_stats(p, data);
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
  printf("  Moves:\n\t1) %s\t2) %s\n\t3) %s\t4) %s\n", p->move1->name, p->move2->name, p->move3->name, p->move4->name);
}

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
  return strsep(&buf, "\n"); // Return the correct entry
}

struct Move *construct_move(int MOVE_ID){
  struct Move *m = malloc(sizeof(struct Move));

  char *data = get_move_entry(MOVE_ID); //grabs data for the move

  m->id = atoi(strsep(&data, ","));
  m->name = strcpy(malloc(50),strsep(&data, ","));
  m->type = atoi(strsep(&data, ","));
  m->power = atoi(strsep(&data, ","));
  m->pp = atoi(strsep(&data, ","));
  m->acc = atoi(strsep(&data, ","));
  m->priority = atoi(strsep(&data, ","));
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

void free_move(struct Move* m) {
  free(m->name);
  free(m);
}

void free_pokemon(struct Pokemon* p) {
  free(p->name);
  free_move(p->move1);
  free_move(p->move2);
  free_move(p->move3);
  free_move(p->move4);
  free(p);
}

// This main is a test, this file is NOT the main file
int main() {

  //int i = 5;
  //  while (--i){
  struct Pokemon *pikachu = construct_pokemon(PIKACHU_IDNO);
  print_pokemon_data(pikachu);
  
  //struct Pokemon *mewTOO = construct_pokemon(MEWTWO_IDNO);
  //printf("mewtwo id: %d\n", MEWTWO_IDNO);
  //print_pokemon_data(mewTOO);

  printmovedata(pikachu->move1);
  
  free_pokemon(pikachu);
}
