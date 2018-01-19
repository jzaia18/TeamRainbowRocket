#include "sharedheader.h"

char **get_move_entries(int *move_ids) {
  return NULL;
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

  char *ret = strcpy(malloc(MAX_LEARNSET_SIZE*4), strsep(&line, ",") + 1);
  *strchr(ret, '"') = 0;

  //printf("Finished running\n");
  free(tmp);
  close(fd);

  //printf("returning\n");

  return ret;
}

int *get_learnset(int poke_id) {
  //getting data
  int *ret = malloc(MAX_LEARNSET_SIZE + 1);
  char *moves = learnset_lookup(poke_id);
  char *tmp = moves;

  char *c;
  
  int i = 0;

  while(moves){
    c = strsep(&moves, ";");
    ret[i] = atoi(c);
    i++;
  }
  //printf("test");

  free(tmp);
  return ret;
}


int main() {
  //learnset_lookup(150);
  
  //printf("%s\n", learnset_lookup(150));
  int *data = get_learnset(150);
  
  int i = 5;
  while(i--){
    printf("%d\n",data[i]);
  }
  
}
