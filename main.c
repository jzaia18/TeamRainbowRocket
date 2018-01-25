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

void save_team(struct Pokemon **team) {
  char *buf = malloc(1000);
  printf("What would you like to call this team? (teams with the same name will be overwritten) ");
  fgets(buf, 100, stdin);
  *strchr(buf, '\n') = 0;

  char *temp = strcpy(calloc(1100, 1), TEAM_DIR);

  int fd = open(strcat(temp, buf), O_RDWR | O_CREAT, 0644);
  printf("Created team file %s\n", temp);

  int i = 0;
  while (team[i]) {
    char * s = deconstruct_to_string(team[i++]);
    write(fd, s, strlen(s));
    write(fd, "\n", 1);
    free(s);
  }

  close(fd);
  free(buf);
  free(temp);
}

struct Pokemon **read_team(const char* teamname) {
  int fd;

  char *temp = strcpy(calloc(1100, 1), TEAM_DIR);
  char *pathname = strcat(temp, teamname);


  if ((fd = open(pathname, O_RDONLY)) == -1) {
    printf("That team doesn't exist.\n");
    free(temp);
    return NULL;
  }
  else { //do the thing
    struct Pokemon **ret = calloc(7, sizeof(struct Pokemon));

    char *buf = calloc(1000, 1);
    char *to_free = buf;
    read(fd, buf, 1000);
    close(fd);

    printf("READ: %s", buf);

    int i = 0;
    char *curr_line = NULL;
    while ((curr_line = strsep(&buf, "\n")))
      ret[i++] = construct_from_string(curr_line);

    free(temp);
    free(to_free);

    return ret;
  }
}

void print_team (struct Pokemon **team) {
  printf("\n%s\nYour team is:\n", cutoff);
  int i = 0;
  while (team[i]) {
    print_pokemon_data(team[i]);
    i++;
  }
}

int main() {
  print_opening();

  char *buf = malloc(1000);
  struct Pokemon **team = NULL;

  int input = 0;
  printf("Welcome to the world of pokemon. Would you like to\n\t1: Use a team I have already created\n\t2: Create a new team\n");
  while (!team) {
    if ((input = get_user_input_int(buf)) < 1 || input > 2) //invalid
      printf("Please choose one of the above options: ");

    else if (input == 1) { // load a team
      printf("What is the name of the team you're loading? ");

      fgets(buf, 100, stdin);
      *strchr(buf, '\n') = 0;
      team = read_team(buf);
      print_team(team);
    }
    else { //create a new team

      printf("How large of a team do you want? (Choose between 1 and 6) ");
      while ((input = get_user_input_int(buf)) < 1 || input > 6) //retry until a valid number is input
        printf("Pokemon teams must have 1-6 pokemon: ");

      printf("\n%s\n\n", cutoff);
      team = create_team(input);

      print_team(team);

      printf("Would you like to save this team? [y/N] ");
      fgets(buf, 100, stdin);
      *strchr(buf, '\n') = 0;
      if(!strcasecmp(buf, "y") || !strcasecmp(buf, "yes"))
        save_team(team);
    }
  }

  free_team(team);
  free(buf);
}
