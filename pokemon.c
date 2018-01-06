#include "sharedheader.h"

// I have decided to write my own csv functions, the ones I found online did not work well for our purposes.
// Extracts one comma-separated line from the csv
char *get_csv_entry(int num) {
  int fd = open(CSV_FILENAME, O_RDONLY);
  if (num < 1 || num > MAX_POKEMON_IDNO)
    return "";

  // read the file in (exact size)
  struct stat ap;
  stat(CSV_FILENAME, &ap);
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

  char *data = get_csv_entry(id_num); //grab comma separated data

  // the following must be executed IN THIS ORDER
  p->id=atoi(strtok(data, ","));
  p->name=strtok(NULL, ",");
  p->type1=atoi(strtok(NULL, ","));
  p->type2=atoi(strtok(NULL, ","));
  set_stats(p); //DO NOT USE OUTSIDE OF THIS FUNCTION

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
}

//TODO
void setMoves(struct Pokemon *p){
  printf("%s\n", p->name);
  //TODO
}

// This main is a test, this file is NOT the main file
int main() {
  struct Pokemon *pikachu = construct_pokemon(PIKACHU_IDNO);
  print_pokemon_data(pikachu);
}
