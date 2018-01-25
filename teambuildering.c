#include "sharedheader.h"

void print_move_entry(struct Move *m) {
  if (!m)
    return;
  printf("%3d: %12s    ", m->id, m->name);
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
    printf("Please input the ID number of the pokemon you want [1,721]: ");
    while ((curr_pokemon_num = get_user_input_int(buf)) < 1 || curr_pokemon_num > MAX_POKEMON_IDNO); //retry until a number is input
    printf("You selected pokemon #%d\n", curr_pokemon_num);

    //TODO: get valid moves

    ret[i] = construct_pokemon(curr_pokemon_num);
    i++;
  }

  free(buf);

  return ret; //temp
}
