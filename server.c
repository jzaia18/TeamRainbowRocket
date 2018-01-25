#include "sharedheader.h"

int main(int argc, char ** argv){
  int i = 0;
  char buffer[64];
  
  
  int[NUM_OF_SOCKETS] listen_sockets = server_setup();
  int[NUM_OF_SOCKETS] connected_sockets;
  
  for(i; i < NUM_OF_SOCKETS; i++){ //set default values to connected_sockets
    connected_sockets[i] = -1;
  }

  while(1){
    //client should try the ports in order, so this will run smoothly
    i = 0; //reset counter
    for (; i < NUM_OF_SOCKETS; i++){
      if (connected_sockets[i] + 1){ //if connected_socket[i] != -1 (connected_socket[i] is not occupied)
	connected_sockets[i] = server_connect(listen_sockets[i]);	
      } else if {
	
      }
    }

  
}
