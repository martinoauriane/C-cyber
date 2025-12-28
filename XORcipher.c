#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char manual_xor(char a, char b){
  if(a == b)
    return '0'; // 0 XOR 0 = 0, 1 XOR 1 = 0
  else 
    return '1'; // O XOR 1 = 1, 1 XOR 0 = 1
}

void xor_binary_manual(const char *binary, const char *key, char *result){
  size_t len = strlen(binary);
  for(size_t i = 0; i<len; i++){
    result[i] = manual_xor(binary[i], key[i]);
  }
  result[len] = '\0';
}

int main(){
  char binary[] = "010100111010001";
  char key[] = "11001001011011010";
  char result[100]; 

  xor_binary_manual(binary, key, result);
  printf("Binary: %s\n", binary);
  printf("Key: %s\n", key);
  printf("XOR: %s\n", result);

  return 0;
}