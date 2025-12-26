#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_ATTEMPTS 3
#define TIME_WINDOW 10 // seconds

const char *authorized_uids[] = {
    "A1B2C3D4",
    "11223344",
    "DEADBEEF"
};

int attempts_nb = 0;
time_t last_scan = 0;

int is_authorized(const char *uuid){
  for(int i = 0; i < 3; i++){
    if(strcmp(authorized_uids[i], uuid) == 0)
      return 1;
    }
  return 0;
}

int detect_skimming()
{
  time_t now = time(NULL);
  if(difftime(now, last_scan) <= TIME_WINDOW){
    attempts_nb ++;
  } else {
    attempts_nb = 1;
  }
  last_scan = now;

  if(attempts_nb > MAX_ATTEMPTS)
  {
    return 1;
  }
  return 0;
}


int main() {
    char uid[32];

    printf("🔒 RFID Blocking Application\n");

    while (1) {
        printf("\nScanner RFID (UID) : ");
        scanf("%s", uid);

        if (detect_skimming()) {
            printf("🚨 ALERTE : Skimming détecté !\n");
            continue;
        }

        if (is_authorized(uid)) {
            printf("✅ Accès autorisé pour UID %s\n", uid);
        } else {
            printf("❌ Accès REFUSÉ : UID non autorisé\n");
        }
    }

    return 0;
}