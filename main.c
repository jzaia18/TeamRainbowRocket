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

int get_user_input_int(char *buf) { //will probably need more stuff in it
  fgets(buf, 100, stdin);
  *strchr(buf, '\n') = 0;
  return atoi(buf);
};

int main() {
  print_opening();

  char *buf = malloc(1000);

  int pokemon_num;
  printf("Please input the number of the pokemon you want: ");
  while ((pokemon_num = get_user_input_int(buf)) < 0 || pokemon_num > MAX_POKEMON_IDNO); //retry until a number is input

  printf("You selected pokemon #%d\n", pokemon_num);

  struct Pokemon *p = construct_pokemon(pokemon_num);

  print_pokemon_data(p);
  //print_move_data(p->move1);

  if (p)
    free_pokemon(p);
  free(buf);
}
