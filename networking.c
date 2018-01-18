#include "sharedheader.h"

void error_check( int i, char *s ) {
  if ( i < 0 ) {
    printf("%s error %d: %s\n", s, errno, strerror(errno) );
    exit(1);
  }
}

/*
  server_setup
    Creates and binds a server side socket
    Sets the socket to the listening state
  Arguments:
