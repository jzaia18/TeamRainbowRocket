#include "sharedheader.h"

void starting_prompt(){

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



void battle_prompt(){

}

void ending_prompt(){

}

int main(int argc, char ** argv){

  starting_prompt();

  printf("start?\n");
  int server_socket;
  char buffer[10000];
  fd_set read_fds;

  printf("wat");
  if (argc == 2){
    printf("if\n");
    server_socket = client_setup(argv[1]);
  } else {
    printf("else\n");
    server_socket = client_setup(IP);
  }


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
        //strcpy(buffer,starting_prompt());
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
