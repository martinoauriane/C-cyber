#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned char magic[8]; // 8 octets that contains the magic number. Unsigned : value between between 0 and 255
    int length; // Real length of magic number. How many octets of magic array are really used
    const char *type; // descriptive text: "PNG Image", "ELF Executable", etc
} MagicFile;

MagicFile magic_db[] = {
    {{0x7F, 'E', 'L', 'F'}, 4, "ELF Executable"}, // magic[8], length, type
    {{0x89, 'P', 'N', 'G', 0x0D, 0x0A, 0x1A, 0x0A}, 8, "PNG Image"},
    {{0xFF, 0xD8, 0xFF}, 3, "JPEG Image"},
    {{'%', 'P', 'D', 'F'}, 4, "PDF Document"},
    {{'P', 'K', 0x03, 0x04}, 4, "ZIP Archive"}
};

// Function that identifies the real type of a file
const *char identify_file_type(const char *filename)
{
  FILE *file = fopen(filename, "rb");
  if (!file)
  {
    return "Cannot open file";
  }

  unsigned char buffer[8] = {0};

  // read the first 8 octets of the file
  // size_t fread( void * buffer, size_t blocSize, size_t blocCount, FILE * stream );                       
  fread(buffer, 1, 8, file);
  fclose(file);

  int db_size = sizeof(magic_db) / sizeof(MagicFile);

  for(int i = 0; i < db_size; i++){
    // int memcmp ( const void * ptr1, const void * ptr2, size_t num );
    //  Compares the first num bytes of the block of memory pointed by ptr1 to the first num bytes pointed by ptr2, 
    // returning zero if they all match or a value different from zero representing which is greater if they do not.
    if(memcmp(buffer, magic_db[i].magic, magic_db[i].length) == 0)
      return magic_db[i].type;
  }
  return "Unknown file type";
}

int main(int argc, char *argv[]){
 if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    const char *type = identify_file_type(argv[1]);
    printf("File: %s\nDetected type: %s\n", argv[1], type);

    return 0;
}