#include "sharedheader.h"

int main(int argc, char ** argv){
  int i = 0;
  char buffer[1000];
  char *buf = malloc(1000);

  //set of file descriptors to read from
  fd_set read_fds;


  int *listen_sockets = server_setup();
  int connected_sockets[NUM_OF_SOCKETS];

  for(; i < NUM_OF_SOCKETS; i++){ //set default values to connected_sockets
    connected_sockets[i] = -1;
  }

  while(1){
    //client should try the ports in order, so this will run smoothly
    i = 0; //reset counter
    //printf("starting to connect\n");
    for (; i < NUM_OF_SOCKETS; i++){ //connect
      if (connected_sockets[i] == -1){ //if connected_socket[i] is not occupied)
        printf("trying server_connect, i = %d\n", i);

        /*================================================================================================================
          HALP! server_connect will not work on the second pass (ie when i = 1)
          Possible places where it went wrong:
          networking.c -> client_setup(): (line 102-119)
          Client did not properly cycle through possible ports to look for an open one
          line 116 probably doesn't do what I expect it to
          should return false if ip & port is occupied
          return true if ip & port is free
          networking.c -> server_connect(): (line 74-85)
          Server failed to accept connection on port 5002 (when i = 1)
          ================================================================================================================*/

        connected_sockets[i] = server_connect(listen_sockets[i]);
        printf("Shutting socket...\n");
        shutdown(listen_sockets[i], SHUT_RD);
        printf("server_connect\n");
      }
    }

    i = 0;
    int count = 0;
    int sd = 0;
    int start = 1;
    char *hold;
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
	  
          select(NUM_OF_SOCKETS, &read_fds, NULL, NULL, NULL);

          //if client1 is ready
          if (FD_ISSET(sd, &read_fds)) {

            if (start) {
              //create team 1
              struct Pokemon **team1 = create_team(7);
              read(sd, buffer, sizeof(buffer));
              strcpy(buf, buffer);
              while ((hold = strsep(&buf, "\n")) && count < 6)
                team1[count++] = construct_from_string(hold);
              count = 0;

              //create team 2
              struct Pokemon **team2 = create_team(7);
              read(connected_sockets[i], buffer, sizeof(buffer));
              strcpy(buf, buffer);
              while ((hold = strsep(&buf, "\n")) && count < 6)
                team2[count++] = construct_from_string(hold);

              start = 0;
            }
	    
            //battle_scene(); //prompt that describes the events of the battle
            write(connected_sockets[i], buffer, sizeof(buffer));
          }
	  
          //if client2 is ready
          if (FD_ISSET(connected_sockets[i], &read_fds)) {

            if (start) {
              //create team 1
              struct Pokemon **team1 = create_team(7);
              read(connected_sockets[i], buffer, sizeof(buffer));
              strcpy(buf, buffer);
              while ((hold = strsep(&buf, "\n")) && count < 6)
                team1[count++] = construct_from_string(hold);
              count = 0;

              //create team 2
              struct Pokemon **team2 = create_team(7);
              read(sd, buffer, sizeof(buffer));
              strcpy(buf, buffer);
              while ((hold = strsep(&buf, "\n")) && count < 6)
                team2[count++] = construct_from_string(hold);

              start = 0;
            }

            //battle_scene(); //prompt that describes the events of the battle
            write(sd, buffer, sizeof(buffer));
          }
        }
      }
    }
  }
}
