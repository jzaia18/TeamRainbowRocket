#include "sharedheader.h"

void starting_prompt(){

  print_opening();

  char *buf = malloc(1000);

  int size = 0;
  printf("How large of a team do you want? (Choose between 1 and 6) ");
  while ((size = get_user_input_int(buf)) < 1 || size > 6) //retry until a valid number is input
    printf("Pokemon teams must have 1-6 pokemon: ");

  printf("\n%s\n\n", cutoff);
  struct Pokemon **team = create_team(size);

  int i = 0;
  while (i < size)
    print_pokemon_data(team[i++]);

  free_team(team);
  free(buf);
}

void battle_scene(){
  

}

int main(int argc, char ** argv){
  int i = 0;
  char buffer[1000];
  
  
  int[NUM_OF_SOCKETS] listen_sockets = server_setup();
  int[NUM_OF_SOCKETS] connected_sockets;
  
  for(i; i < NUM_OF_SOCKETS; i++){ //set default values to connected_sockets
    connected_sockets[i] = -1;
  }

  while(1){
    //client should try the ports in order, so this will run smoothly
    i = 0; //reset counter
    for (; i < NUM_OF_SOCKETS; i++){ //connect
      if (connected_sockets[i] + 1){ //if connected_socket[i] != -1 (connected_socket[i] is not occupied)
	connected_sockets[i] = server_connect(listen_sockets[i]);	
      }
      
    }

    i = 0;
    int started_server = 1;
    int started_client = 1;
    int sd = 0;
    for(; i < NUM_OF_SOCKETS; i++){
      if (connected_sockets[i] + 1){
	if (sd == 0)
	  sd = connected_sockets[i];
	else{
	  //connect the clients
	  
	  //select() modifies read_fds
	  //we must reset it at each iteration
	  FD_ZERO(&read_fds);
	  FD_SET(sd, &read_fds); //add stdin to fd set
	  FD_SET(connected_sockets[i], &read_fds); //add socket to fd set
	  
	  select(server_socket + 1, &read_fds, NULL, NULL, NULL);

	  //server
	  if (FD_ISSET(sd, &read_fds)) {
	    if (started_server) { //runs only at the start
	      starting_prompt(); //prompt for initializing the teams
	      started_server = 0; 
	    }
	    read(sd, buffer, sizeof(buffer));
	    construct_from_string(buffer);
	    battle_scene(); //prompt that describes the events of the battle
	    write(server_socket[i], buffer, sizeof(buffer));
	  }
	  
	  //client
	  if (FD_ISSET(server_socket[i], &read_fds)) {
	    if (started_client) { //runs only at the start
	      starting_prompt(); //prompt for initializing the teams
	      started_client = 0; 
	    }
	    read(server_socket[i], buffer, sizeof(buffer));
	    battle_scene(); //prompt that describes the events of the battle
	    write(sd, buffer, sizeof(buffer));
	    deconstruct_to_string();
	  }
	}
      }
    }
  }
}
