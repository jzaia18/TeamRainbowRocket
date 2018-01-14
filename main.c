#include "sharedheader.h"


void print_opening() {
  printf("%s\n\n", cutoff);
  printf("\e[33m                                 .::.                                 \n");
  printf("                               .;:**                                  \n");
  printf("                               `                                      \n");
  printf("   .:XHHHHk.              db.   .;;.     dH  MX                       \n");
  printf(" oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN            \n");
  printf(" QMMMMMb   MMX       MMMMMMP !MX^ :M~   MMM MMM  .oo. XMMM  MMM       \n");
  printf("   `MMMM.  )M> :X!Hk. MMMM   XMM.o^  .  MMMMMMM X?XMMM MMM>!MMP       \n");
  printf("    ^MMMb.dM! XM M^?M MMMMMX.`MMMMMMMM~ MM MMM XM `^ MX MMXXMM        \n");
  printf("     ~MMMMM~ XMM. .XM XM`^MMMb.~*?**~ .MMX V t MMbooMM XMMMMMP        \n");
  printf("      ?MMM>  YMMMMMM! MM   `?MMRb.    `MMM   !L;MMMMM XM IMMM         \n");
  printf("       MMMX   ^MMMM^  MM       ~&:           !Mh.    dMI IMMP         \n");
  printf("       ^MMM.                                             IMX          \n");
  printf("        ~M!M                                             IMP          \e[0m\n");
  printf("\n\nA game by Leo Liu, Piotr Milewski, Jake Zaia, & Rihui Zheng. Enjoy.\n\n%s\n\n", cutoff);
}

void get_user_input(char *buf) { //will probably need more stuff in it
  fgets(buf, 100, stdin);
  *strchr(buf, '\n') = 0;
};

int main() {
  print_opening();

  char *buf = malloc(1000);

  struct Pokemon *pikachu = construct_pokemon(PIKACHU_IDNO);
  print_pokemon_data(pikachu);
  print_move_data(pikachu->move1);

  free_pokemon(pikachu);
  free(buf);
}
