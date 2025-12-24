// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int length(char *string){
    int i;
    i = 0;
    while(string[i] != '\0')
    {
        i++;
    }
    return i;
}
void generatePassword(char *pass, int passLen){
    char alphabet[] = "0123456789abcdefghijklmnoqprstuvwyzxABCDEFGHIJKLMNOQPRSTUYWVZX!@#$^&*?";

    int alphaLen = length(alphabet);
    for(int i =0; i <passLen; i++){
    pass[i] = alphabet[rand() % alphaLen];
    }
    pass[i] = '\0';
}

int main() {
    char password[96];
    int N = 20;
    
    if(N >= 96)
        return 1;
    
    generatePassword(password, N);
    printf("Your password is %s\n", buffer);
    
    return 0;
  }