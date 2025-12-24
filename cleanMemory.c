#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 128

size_t length(const char *string)
{
    size_t i = 0;
    while (string[i])
        i++;
    return i;
}

void secure_bzero(void *ptr, size_t len)
{
    volatile unsigned char *p = ptr;
    while (len--)
        *p++ = 0;
}

int scan_memory(const unsigned char *buf, size_t len, const char *pattern)
{
    size_t pattern_len = length(pattern);

    for (size_t i = 0; i + pattern_len <= len; i++)
    {
        size_t j = 0;
        while (j < pattern_len && buf[i + j] == (unsigned char)pattern[j])
            j++;

        if (j == pattern_len)
            return 1;
    }
    return 0;
}

int main(void)
{
    char *buffer = malloc(BUF_SIZE);
    if (!buffer)
        return 1;

    const char *secret = "SuperSecretPassword123!";
    size_t secret_len = length(secret);

    for (size_t i = 0; i < secret_len && i < BUF_SIZE - 1; i++)
        buffer[i] = secret[i];

    buffer[secret_len] = '\0';
    printf("secret: %s\n", buffer);

    secure_bzero(buffer, BUF_SIZE);

    if (scan_memory((unsigned char *)buffer, BUF_SIZE, secret))
        printf("⚠️ Secret still in memory\n");
    else
        printf("✅ Memory clean\n");

    free(buffer);
    return 0;
}
