#include <stdio.h>

void vulnerable()
{
  char buffer[16];
  printf("Entrez votre nom:");
  scanf("%s", buffer);
  printf("Bonjour, %s\n", buffer);
}

void detect_overflow(char *input)
{
  // here, overflow is avoided. 
  char buffer[16];
  strncpy(buffer, input, sizeof(buffer)-1);
  buffer[15] = '\0';
}

int main()
{
  vulnerable();
  return 0;
}