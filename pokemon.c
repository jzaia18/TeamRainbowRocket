#include "sharedheader.h"

// I have decided to write my own csv functions, the ones I found online did not work well for our purposes.
char *getcsventry(int num) {
  int fd = open(CSV_FILENAME, O_RDONLY);
  if (num < 1 || num > MAX_POKEMON_IDNO)
    return "";

  // read the file in (exact size)
  struct stat ap;
  stat(CSV_FILENAME, &ap);
  char buf[ap.st_size+15];
  read(fd, buf, sizeof(buf));

  // The 1st line (header line)
  strtok(buf, "\n");

  char i = num - 1;
  while (i-- > 0) strtok(NULL, "\n"); // Run down the entries in the list
  return strtok(NULL, "\n");
}


struct Pokemon* construct_pokemon(int choice) {
  struct Pokemon *p = calloc(sizeof(struct Pokemon), 1); //needs default 0s

  switch(choice) {
  case PIKACHU_IDNO:
    p->name = "Pikachu";
    p->maxhp = randr(0, 47) + 95;
    p->atk = randr(0, 63) + 54;
    p->def = randr(0, 61) + 40;
    p->spatk = randr(0, 63) + 49;
    p->spdef = randr(0, 63) + 49;
    p->speed = randr(0, 71) + 85;
    p->type1 = ELECTRIC_TYPENO;
  case 0:
  default:
    return 0;
  }

  p->currhp=p->maxhp; //set hp to full
  return p;
}


void setMoves(struct Pokemon *p){
  //TODO
}


int main() {
  char i = 1;
  for(; i < 10; i++)
    printf("%s\n", getcsventry(i));
}
