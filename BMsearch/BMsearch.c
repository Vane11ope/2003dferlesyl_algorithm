#include "stdio.h"
#define max(a, b) ((a) > (b) ? a : b)

int BMsearch(unsigned char *text, unsigned char *pattern);
int length(unsigned char *text);
int main(void);

int main(void)
{
    unsigned char text[] = "14243593";
    unsigned char pattern[] = "359";
    printf("%d", BMsearch(text, pattern));
    return 0;
}

int BMsearch(unsigned char *text, unsigned char *pattern)
{
    int skip[256];
    int i, j;
    int textlen = length(text);
    int patlen = length(pattern);
    for (i = 0; i < 256; ++i) skip[i] = patlen;
    for (i = 0; i < patlen - 1; ++i) skip[pattern[i]] = patlen - i - 1;
    i = patlen - 1;
    while (i < textlen) {
        j = patlen - 1;
        while (text[i] == pattern[j]) {
            if (j == 0) return i;
            --i, --j;
        }
        i = i + max(skip[text[i]], patlen - j);
    }
    return -1;
}

int length(unsigned char *text)
{
    int len = 0;
    for(;*text != 0x00; ++text){
        ++len;
    }
    //printf("%d\n", len);
    return len;
}
