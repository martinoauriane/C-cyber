#define MAX_IPS 1000
#define MAX_LINE 512


typedef struct { // a struct to store IP addresses<Q  
    char ip[50];
    int failed_attempts;
} IPRecord;

