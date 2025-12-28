#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 256

void swap(unsigned char *a, unsigned char *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// KSA = Key Scheduling Algorithm

// the KSA step prepares the s array of 256. First, 
// it initializes the array with 256 values. 
// Then, it mixes the array using the key provided by the user. 
// j = (j + S[i] + key[i mod key_length]) mod 256
// Finally, swaping j and i values within S : swap(&S[i], &S[j])
// Final result = S is fully mixed. This mix depends entirely on the key. 
// This final S version will be used in the PRGA, in order to generate keystream.
int KSA(char *key, unsigned char *S){
  int len = strlen(key);
  int j = 0;

  for(int i = 0; i<N; i++)
    S[i] = i;

  for(int i = 0; i< N; i++){
    j = (j + S[i] + key[i%len]) % N;
    swap(&S[i], &S[j]);
  }
  return 0;
}

// PRGA = Pseudo-Random Generation Algorithm

// The goal of the PRGA (Pseudo-Random Generation Algorithm) is to generate the keystream
// Then, using that keystream, XORING the original plain text octet by octet. 
int PRGA(unsigned char *S, char *plaintext, unsigned char *ciphertext){
  int i = 0;
  int j = 0;

  for(size_t n = 0, len = strlen(plaintext); n < len; n++){
    // gradually incrementing i at each turn. i = 1, then i = 2, then i = 3... etc. 
    i = (i + 1) % N;
    j = (j + S[i]) % N;
    swap(&S[i], &S[j]);
    int keystream = S[(S[i] + S[j]) % N];

    // encoding plaintext with the specific keystream
    ciphertext[n] = keystream ^ plaintext[n];
  })
  return 0;
}

int RC4(char *key, char *plaintext, unsigned char *ciphertext){
  unsigned char S[N];
  KSA(key, S);
  PRGA(S, plaintext, ciphertext);
  return 0;
}

int main(int argc, char *argv[]){
  if(argc < 3){
    printf("Usage : %s <key> <plaintext>", argv[0]);
    return -1;
  }

  unsigned char *ciphertext = malloc(sizeof(unsigned char) * strlen(argv[2]));
  RC4(argv[1], argv[2], ciphertext);

  // printing new encoded message
  for(size_t i = 0, len = strlen(argv[2]); i < len; i++)
    printf("%02hhX", ciphertext[i]);

  return 0;
}