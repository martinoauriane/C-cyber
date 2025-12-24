// Online C compiler to run C program online
#include <stdio.h>
#define MIN_LEN 8
#define MAX_LEN 64

void erasePassword(char *password, size_t len)
{
    char *p = password;
    while(len--){
        *p++ = 0;
    }
}
int checkPassword(char *password){
    int i =0;
    int uppercase = 0;
    int lowercase = 0;
    int digits = 0;
    int len = 0;
    
    while(password[i] != '\0')
    {
        char c = password[i];
        
        if(c >= 'A' && c <= 'Z')
            uppercase ++;
        else if(c >= 'a' && c <= 'z')
            lowercase ++;
        else if(c >= '0' && c <= '9')
            digits ++;
        
        i++;
        len++;
    }
    
    if(len > MAX_LEN)
        return 1;
    if (len < MIN_LEN)
        return 1;
        
    if(uppercase < 2 || lowercase < 2 || digits <2)
        return 1;
    return 0;
}
int main() {
    char password[96];
    printf("Please enter your password");
    scanf("%95s", password);
    int so = checkPassword(password);
    printf("so = %d\n", so);
    return 0;
}