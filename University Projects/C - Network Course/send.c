#include <sys/types.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define CLNAME 111

int main(int argc, char *argv[])
{
  int socket_fd; // create a socket
  struct sockaddr_in  dest; ///address for the socket, server address
  struct hostent *hostptr; //host name by ip
  struct { char head; u_long body; char tail; } msgbuf;

  socket_fd = socket (AF_INET, SOCK_DGRAM, 0);
  //call the socket function, 
  //AF_INET - inetnet socket defined in the header files, sock is the type of the socket
  // TCP or UDP
  // 0 is the protocol, 0 is the default protocol
  
  memset((char *) &dest,0, sizeof(dest)); //reset the msg
  hostptr = gethostbyname(argv[1]);
  dest.sin_family = (short) AF_INET;//family of the address
  memcpy(hostptr->h_addr, (char *)&dest.sin_addr,hostptr->h_length);
  dest.sin_port = htons((u_short)0x3333);  // convert the decimal 13107 to TCP/IP network byte order port value

  msgbuf.head = '<';
  msgbuf.body = htonl(getpid()); 
  msgbuf.tail = '>';

  // Send message to socket 
  sendto(socket_fd,&msgbuf,sizeof(msgbuf),0,(struct sockaddr *)&dest, sizeof(dest));
  printf("Client sent data ::%c%ld%c\n",msgbuf.head, (long) ntohl(msgbuf.body), msgbuf.tail); 
  // stores msg in msgbuf
  recvfrom(socket_fd,&msgbuf,sizeof(msgbuf),0,(struct sockaddr *)&dest, sizeof(dest));
  // Print prompt
  printf("Client got data ::%c%ld%c\n",msgbuf.head,(long) ntohl(msgbuf.body),msgbuf.tail); 


  return 0;
}
