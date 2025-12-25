#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
  int sockfd;
  struct sockaddr_in target_addr;
  target_addr.sin_family = AF_INET;
  target_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // scan localhost

  for(int port = 1; port <= 1024; port++){
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // creating the socket
    if(sockfd < 0){
      perror("Socket creation failed");
      continue;
    }
    target_addr.sin_port = htons(port);
    // trying to establish a TCP connexion with this address 
    if (connect(sockdf, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0){
      // if connect returns 0, then there is a processus listenning on this port and the TCP connexion was successful
      // if connect returns -1, the port is closed.
      printf("Port %d is open\n", port);
    }
    close(sockfd);
  }
}