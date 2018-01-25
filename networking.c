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
  //int numOfSockets = 2;
  //Now done in sharedheader.h

  //storage for the socket descriptor
  int *sd = calloc(NUM_OF_SOCKETS, sizeof(int));

  //create the sockets
  for (; i < NUM_OF_SOCKETS; i++){
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
    sprintf( s, "%d", PORT + i);
    getaddrinfo(IP, s, hints, &results); //sets IP to local address 

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
  int client_socket;
  socklen_t sock_size;
  struct sockaddr_storage client_address;
  sock_size = sizeof(client_address);

  client_socket = accept(sd, (struct sockaddr *)&client_address, &sock_size);
  error_check(client_socket, "server accept");


  return client_socket;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~
  client_setup
    create and connect a socket to a server socket that is in the listening state
  Arguments: int * to_server
    to_server is a string representing the server address
  Return:
    The file descriptor for the socket
  ~~~~~~~~~~~~~~~~~~~~~~~~~*/
int client_setup(char * server) {
  printf("client setup started\n");
  //used for incrementation and storage
  int sd;
  int i = 0; //utilized for error checking and standard incrementation
  char s[64];
  
  //create the socket
  sd = socket (AF_INET, SOCK_STREAM, 0);
  error_check( sd, "client socket" );

  printf("socket created\n");
  //run getaddrinfo
  struct addrinfo * hints, * results;
  hints = (struct addrinfo *)calloc(1, sizeof(struct addrinfo));
  hints->ai_family = AF_INET;  //IPv4
  hints->ai_socktype = SOCK_STREAM;  //TCP socket
  for (; i < NUM_OF_SOCKETS; i++){
    sprintf( s, "%d", PORT + i);
    getaddrinfo(server, s, hints, &results);
    printf("trying port %s\n", s);
    if ((i = connect( sd, results->ai_addr, results->ai_addrlen )) == 0){  
      printf("found an open port\n");
    break;
    }
  }

  //connect to the server
  //connect will bind the socket for us
  
  error_check( i, "client connect" );

  
  //if client1 is ready

  printf("connected\n");
  
  free(hints);
  freeaddrinfo(results);
  

  return sd;
}
