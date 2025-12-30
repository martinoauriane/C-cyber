#include <stdio.h>
#include <stdlib.h>

void list_wifi_networks()
{
  printf("Here's the list of available wifis in your network");
}

void executeNmcli(char *ssid, char *password){

  // 1. build command
  char command[256];
  int result;
  result = 0;
  // snprintf(command, sizeof(command), "nmcli device wifi connect \"%s\" password \"%s\"", *ssid, *password);
  // Why it is wrong : ssid and password are already chains (char *) => *ssid = one character, not the chain
  // 
  snprintf(command, sizeof(command), "nmcli device wifi connect \"%s\" password \"%s\"", ssid, password);
  
  // 2. execute command
  // The C stdlib library system() function is used to execute an operating system command
  // it returns an integer status indicating the success or failure of the command execution.
  result = system(command);

  // 3. check for command failure/success
  if(result == 0){
    printf("You're now successfully connect to %s Wifi", ssid);
  } else {
    printf("Connection failed. Wrong password, or network not found.\n");
  }
}
int main() { 
    // 1. Display list of available networks
    list_wifi_networks();

    // 2. Get user choice (Wifi connection + password)
    char SSID[96];
    char password[96];
    printf("Enter the name (SSID) of the Wi-Fi-network you want to connect to:\n");
    scanf("%95s", SSID);
    if(SSID[0] == '\0'){
      printf("Error. Empty SSID");
      return 1;
    }
    printf("Enter the password for the Wi-Fi network:");
    scanf("%95s", password);
    
    // 3. Try to connect to Wifi using nmcli
    executeNmcli(password, SSID);
    return 0;
  }