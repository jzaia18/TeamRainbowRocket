#include "sharedheader.h"

char *starting_prompt(){

  print_opening();

  char *buf = malloc(1000);

  int size = 0;
  printf("How large of a team do you want? (Choose between 1 and 6) ");
  while ((size = get_user_input_int(buf)) < 1 || size > 6) //retry until a valid number is input
    printf("Pokemon teams must have 1-6 pokemon: ");

  printf("\n%s\n\n", cutoff);
  struct Pokemon **team = create_team(size);

  char *storage = malloc(10000);
  int i = 0;
  while (i < size) {
    print_pokemon_data(team[i++]);
    char * s = deconstruct_to_string(team[i]);
    strcat(storage, "\n");
    strcat(storage, s);
    free(s);
    i++;
  }
  
  free_team(team);
  free(buf);

  return storage;
}

void battle_prompt(){

}

void ending_prompt(){

}

int main(int argc, char ** argv){
  int server_socket;
  char buffer[10000];
  fd_set read_fds;

  if (argc == 2)
    server_socket = client_setup(argv[1]);
  else
    server_socket = client_setup("127.0.0.1");

  int started = 1;
  while (1){
    
    printf("enter text to send: ");
    
    //select() modifies read_fds
    //we must reset it at each iteration
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds); //add stdin to fd set
    FD_SET(server_socket, &read_fds); //add socket to fd set
    
    select(server_socket + 1, &read_fds, NULL, NULL, NULL);

    //if client is ready
    if (FD_ISSET(STDIN_FILENO, &read_fds)) {
      if (started) { //runs only at the start
	strcpy(buffer,starting_prompt());
	started = 0;
      }
      else {
	battle_prompt();
      }
      write(server_socket, buffer, sizeof(buffer));
      //Do we really want to read here? We don't know
    }

    //if server is ready
    if (FD_ISSET(server_socket, &read_fds)) {
      read(server_socket, buffer, sizeof(buffer));
      printf("recieved: %s\n", buffer);
    }
  }
}
