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

int main() {
  print_opening();

  char *buf = malloc(1000);

  int size = 0;
  printf("How large of a team do you want? (Choose between 1 and 6) ");
  while ((size = get_user_input_int(buf)) < 1 || size > 6) //retry until a valid number is input
    printf("Pokemon teams must have 1-6 pokemon: ");

  printf("\n%s\n\n", cutoff);
  struct Pokemon **team = create_team(size);

  printf("\n%s\nYour team is:\n", cutoff);
  int i = 0;
  while (i < size) {
    print_pokemon_data(team[i]);
    /*    char * s = deconstruct_to_string(team[i]);
    struct Pokemon *p = construct_from_string(s);
    print_pokemon_data(p);
    free_pokemon(p);
    free(s);*/
    i++;
  }

  printf("Would you like to save this team? [y/N] ");

  free_team(team);
  free(buf);
}
