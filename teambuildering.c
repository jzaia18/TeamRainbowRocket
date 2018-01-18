#include "sharedheader.h"

char **get_move_entries(int *move_ids) {
  return NULL;
};

char *learnset_lookup(int poke_id) {
  int fd = open(POKEDATA_CSV, O_RDONLY);

  struct stat ap;
  stat(POKEDATA_CSV, &ap);
  char file[ap.st_size+15];
  printf("Reading file\n");
  read(fd, file, sizeof(file));
  printf("Read file\n");

  char *buf = file;

  int i = poke_id;
  while (i-- > 0) strsep(&buf, "\n"); // Run down the entries in the list

  char *line = strcpy(malloc(1000), strsep(&buf, "\n"));
  printf("Line: %s\n", line);

  i = POKEDATA_LEARNSET_INDEX;
  while (i-- > 0) strsep(&line, ",");

  char *ret = strcpy(malloc(MAX_LEARNSET_SIZE*4), strsep(&line, ","));
  //*strchr(ret, '"') = 0;

  printf("Finished running\n");
  free(file);
  free(line);
  close(fd);

  printf("returning\n");

  return NULL;
}

int *get_learnset(int poke_id) {
  malloc(MAX_LEARNSET_SIZE + 1);

  return NULL;
}


int main() {
  learnset_lookup(150);
  //printf("%s\n", learnset_lookup(150));
}
