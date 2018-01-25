#include "sharedheader.h"

void print_move_entry(struct Move *m) {
  if (!m)
    return;
  printf("%3d: %14s    ", m->id, m->name);
  printf("type: %8s   ", type_lookup(m->type));
  printf("power: %3d   ", m->power);
  printf("accuracy: %3d   ", (int) m->acc);
  printf("priority: %d\n", m->priority);
};

char *learnset_lookup(int poke_id) {
  int fd = open(POKEDATA_CSV, O_RDONLY);

  struct stat ap;
  stat(POKEDATA_CSV, &ap);
  char file[ap.st_size+15];
  //printf("Reading file\n");
  read(fd, file, sizeof(file));
  //printf("Read file\n");

  char *buf = file;

  int i = poke_id;
  while (i-- > 0) strsep(&buf, "\n"); // Run down the entries in the list

  char *line = strcpy(malloc(1000), strsep(&buf, "\n"));
  //printf("Line: %s\n", line);

  char *tmp = line;

  i = POKEDATA_LEARNSET_INDEX;
  while (--i > 0) strsep(&line, ",");

  char *ret = malloc(MAX_LEARNSET_SIZE * sizeof(int));
  strcpy(ret, strsep(&line, ",") + 1);

  *strchr(ret, '"') = 0;

  //printf("Finished running\n");
  free(tmp);
  close(fd);

  //printf("returning\n");

  return ret;
}

// Converts csv entry into an array of ints
int *get_learnset(int poke_id) {
  //getting data
  int *ret = malloc(MAX_LEARNSET_SIZE * sizeof(int) + 1);
  char *moves = learnset_lookup(poke_id);
  char *tmp = moves;

  char *c = 0;
  int i = 0;

  while( (c = strsep(&moves, ";")) ){
    ret[i] = atoi(c);
    i++;
  }

  ret[i] = 0;

  free(tmp);
  return ret;
}

void print_poke_choices(){

  //printf("successfully read");
  //reads all pokemon data
  int fd = open(POKEDATA_CSV, O_RDONLY);
  struct stat ap;
  stat(POKEDATA_CSV, &ap);
  char file[ap.st_size+15];
  read(fd, file, sizeof(file));
  
  
  //gets rid of first line
  char *buf = file;
  strsep(&buf, "\n");
  close(fd);

  
  int i = MAX_POKEMON_IDNO;
  int stop = i - 50;
  while (i > 0){
    while (i > stop){
      char *line = strsep(&buf, "\n");//next entry
      //printf("line: %s\n", line);
      int id = atoi(strsep(&line,","));
      char *name = strsep(&line,",");
      int type1_no = atoi(strsep(&line, ","));
      int type2_no = atoi(strsep(&line, ","));
    
      printf("id: %d\tname: %20s\ttype1: %s\ttype2: %s\n", id, name, type_lookup(type1_no), type_lookup(type2_no));

      i--;
    }

    printf("Press 'n' for next page, 'q' to quit: ");

    char buf[100];
    fgets(buf, 100, stdin);
    *strchr(buf, '\n') = 0;
    if(!strcmp(buf, "n")){
      stop = MAX(0, stop - 50);
    }

    else if(!strcmp(buf, "q"))
      break;

    else
      printf("Press 'n' for next page, 'q' to quit: ");
  }

}

void print_move_choices(int pokemon_id) {
  int *moves = get_learnset(pokemon_id);
  int i = 0;
  while (moves[i]) {
    struct Move *m = construct_move(moves[i]);
    print_move_entry(m);
    free_move(m);
    i++;
  }
  printf("\n");

  free(moves);
}

void free_team(struct Pokemon** team) {
  int i = 0;
  while (team[i]) {
    free_pokemon(team[i]);
    i++;
  }
  free(team);
}

int move_is_legal(int pokenum, int movenum) {
  int *temp = get_learnset(pokenum);

  int i = 0;
  while (temp[i]) {
    if (movenum == temp[i++]) {
      free(temp);
      return 1; //is legal
    }
  }

  free(temp);
  return 0; //is illegal
}

int get_user_input_pokemon(char *buf) {
  fgets(buf, 100, stdin);
  *strchr(buf, '\n') = 0;
  if(!strcmp(buf, "help")){
    //printf("successfully read");
    print_poke_choices();
    printf("\nPlease input the ID number of the pokemon you want [1,721] (or type 'help' for a list of pokemon): ");
    return 0;
  }
  else {
    return atoi(buf);
  }
}

struct Pokemon **create_team(int size) {
  if (size > 6 || size < 1) {
    printf("Pokemon teams must have 1-6 pokemon\n");
    return NULL;
  }

  struct Pokemon **ret = calloc(sizeof(struct Pokemon), size + 1);

  char *buf = malloc(1000);

  int i = 0;
  while (i < size) {
    int curr_pokemon_num;
    printf("Please input the ID number of the pokemon you want [1,721] (or type 'help' for a list of pokemon): ");
    while ((curr_pokemon_num = get_user_input_pokemon(buf)) < 1 || curr_pokemon_num > MAX_POKEMON_IDNO)
      printf("\nPlease choose a valid pokemon id: "); //retry until a number is input;

    printf("\nChoose 2 of the following stats to max:\n");
    printf("\t1: hp\n\t2: atk\n\t3: def\n\t4: spatk\n\t5: spdef\n\t6: speed\n\t7: balance it! (balances all stats and ignores other choice)\n");

    int ev1, ev2;
    printf("Choose stat 1: ");
    while ( (ev1 = get_user_input_int(buf)) < 1 || ev1 > 7)
      printf("Illegal input, please choose a valid number: ");
    printf("Choose stat 2: ");
    while ( (ev2 = get_user_input_int(buf)) < 1 || ev2 > 7 || ev2 == ev1)
      printf("Illegal input, please choose a valid number: ");

    printf("You selected pokemon #%d\n", curr_pokemon_num);
    printf("Please select the move you want. Moves for pokemon #%d:\n", curr_pokemon_num);
    print_move_choices(curr_pokemon_num);


    int m1, m2, m3, m4;
    printf("\nChoose move number 1: ");
    while (!move_is_legal(curr_pokemon_num, m1 = get_user_input_int(buf)))
      printf("Illegal input, please choose a valid number: ");
    printf("\nChoose move number 2: ");
    while (!move_is_legal(curr_pokemon_num, m2 = get_user_input_int(buf)) || m2 == m1)
      printf("Illegal input, please choose a valid number: ");
    printf("\nChoose move number 3: ");
    while (!move_is_legal(curr_pokemon_num, m3 = get_user_input_int(buf)) || m3 == m2 || m3 == m1)
      printf("Illegal input, please choose a valid number: ");
    printf("\nChoose move number 4: ");
    while (!move_is_legal(curr_pokemon_num, m4 = get_user_input_int(buf)) || m4 == m3 || m4 == m2 || m4 == m1)
      printf("Illegal input, please choose a valid number: ");


    ret[i] = construct_pokemon(curr_pokemon_num, m1, m2, m3, m4, ev1, ev2);
    i++;
  }

  free(buf);

  return ret;
}
