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
int server_setup() {
  //used for incrementation and storage
  int i = 0;
  char s[64];
  
  //set the amount of sockets
  int numOfSockets = 2;

  //storage for the socket descriptors
  int sd[numOfSockets];

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
    i = bind( sd[0], results->ai_addr, results->ai_addrlen );
    error_check( i, "server binding" );
    printf("[server] socket bound\n");

    //set socket to listen state
    i = listen(sd, 10);
    error_check( i, "server listen" );
    printf("[server] socket in listen state\n");

    //free the structs used by getaddrinfo
    free(hints);
    freeaddrinfo(results);
    return sd;
  }
