#include "sharedheader.h"

void server(int ip, int port){

  int listen_socket;
  int clients[2];
  char buffer[BUFFER_SIZE];
  int client_counter;
  
  // create & bind a server socket to IP & port
  listen_socket ;

  //do next two things at the same time
    
  // wait for clients to connect
  clients[client_counter] = ;

  // match the two clients for a match
  
  // fork off the two to subserver
  if(0 == fork()){
    //subserver
  } else {
    //server goes back to waiting/matching
  } 

  // establish connection to both clients

  // relay info between the two clients
}
