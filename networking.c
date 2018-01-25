#include "sharedheader.h"

void error_check( int i, char *s ) {
  if ( i < 0 ) {
    printf("%s error %d: %s\n", s, errno, strerror(errno) );
    exit(1);
  }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~
  server_setup
    Creates and binds a server side socket
    Sets the socket to the listening state
  Arguments:
    None
  Return:
    int Socket Descriptor
~~~~~~~~~~~~~~~~~~~~~~~~~*/
int *server_setup() {

  //used for incrementation and storage
  int n;
  int i = 0;
  char s[64];
  
  //set the amount of sockets
  int numOfSockets = 2;

  //storage for the socket descriptors
  int *sd = calloc(numOfSockets, sizeof(int));

  //create the sockets
  for (; i < numOfSockets; i++){
    sd[i] = socket( AF_INET, SOCK_STREAM, 0 ); 
    sprintf( s, "Server socket[%d] creation", i); 
    error_check( sd[i], s ); 
    printf("[server] socket[%d] created\n", i); 
  
    //setup structs for getaddrinfo 
    struct addrinfo *hints, *results; 
    hints = (struct addrinfo *)calloc(1, sizeof(struct addrinfo)); 
    hints->ai_family = AF_INET;  //IPv4 address 
    hints->ai_socktype = SOCK_STREAM;  //TCP socket 
    hints->ai_flags = AI_PASSIVE;  //Use all valid addresses 
    getaddrinfo(NULL, 5001 + i, hints, &results); //NULL -> local address 

    //bind socket[i] to address and port 
    n = bind( sd[i], results->ai_addr, results->ai_addrlen ); 
    error_check( n, "server binding" ); 
    printf("[server] socket bound\n"); 

    //set socket to listen state 
    n = listen(sd[i], 10); 
    error_check( n, "server listen" ); 
    printf("[server] socket in listen state\n");

    //free the structs used by getaddrinfo 
    free(hints); 
    freeaddrinfo(results); 
  }
  return sd;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~
  server_connect
    run the accept call
  Arguments: int sd
    sd should refer to a socket in the listening state
  Return:
    The socket descriptor for the new socket connected to the client.
  ~~~~~~~~~~~~~~~~~~~~~~~~~*/
int server_connect(int sd) {
  int client_sock;
  struct sockaddr_storage client_address;
  socklen_t sock_size = sizeof(client_address);

  client_socket = accept(sd, (struct sockadd *)&client_address, &sock_size);
  error_check(client_socket, "server acceptance");

  return client_socket;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~
  client_setup
  args: int * to_server
  to_server is a string representing the server address
  create and connect a socket to a server socket that is
  in the listening state
  returns the file descriptor for the socket
  ~~~~~~~~~~~~~~~~~~~~~~~~~*/
int client_setup(char * server) {

  //used for incrementation and storage
  int sd, i;

  //create the socket

  //run getaddrinfo
  /* hints->ai_flags not needed because the client
     specifies the desired address. */


  //connect to the server
  //connect will bind the socket for us
  
}
