#include "sharedheader.h"

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
