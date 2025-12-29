#include <stdio.h>
#include <math.h>

double calculate_entropy(const char *filename) {
    FILE *file = fopen(filename, "rb"); // read binary mode
    if (!file) return 0.0;
    int freq[256] = {0}; // freq[65] = number of times 65 ('A') appears
    int c;
    long size = 0;

    while ((c = fgetc(file)) != EOF) { // reads one octet
      freq[c]++; // counting that octet. Example: AAAAAB. freq['A'] = 5 freq['B'] = 1 size = 6
      size++; // total size of the file.
    }
    fclose(file);
    double entropy = 0.0;

    for (int i = 0; i < 256; i++) {
      if (freq[i] == 0) continue; // ignoring octets that do not appear
      double p = (double)freq[i] / size; // calculating the probability of seeing one octet in the file. Example: 'A' apparaît 50 fois dans un fichier de 100 octets
      // p = 50/100 = 0.5
      entropy -= p * log2(p); // Shannon's formula
    }
    return entropy;
}

int main(int argc, char *argv){
  if(argc < 2){
    printf("Error. At least two args are needed. Please enter the name of the file you'd like to the calculate the entropy for. <./fileEntropy.c> <filename>");
    return 1;
  }
  double entropy = 0;
  entropy = calculate_entropy(argv[1]);
  printf("L'entropie du fichier %s est égale à %lf\n", argv[1], entropy); 
}
