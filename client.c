#include "sharedheader.h"

int main(int argc, char ** argv){
  int server_socket;
  char buffer[64];
  fd_set read_fds;

  if (argc == 2)
    server_socket = client_setup(argv[1]);
  else
    server_socket = client_setup(/* INSERT IP & PORT HERE */);

  while (1){
    
    printf("enter text to send: ");
    
    //select() modifies read_fds
    //we must reset it at each iteration
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds); //add stdin to fd set
    FD_SET(server_socket, &read_fds); //add socket to fd set
    
    select(server_socket + 1, &read_fds, NULL, NULL, NULL);
    
    if (FD_ISSET(STDIN_FILENO, &read_fds)) {
      fgets(buffer, sizeof(buffer), stdin);
      *strchr(buffer, '\n') = 0;
      write(server_socket, buffer, sizeof(buffer));
      //Do we really want to read here?
    }

    if (FD_ISSET(server_socket, &read_fds)) {
      read(server_socket, buffer, sizeof(buffer));
      printf("recieved: %s\n", buffer);
    }
  }
}
