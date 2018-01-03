#include "sharedheader.h"


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
