#include <stdlib.h>

char* convert(char* s, int n) {
    int len =0;
    for(;s[len]!='\0';len++);
    char* r = (char*)malloc(len+1);

    int crow = 0;
    int count = 0;
    int j = 0;
    int offset = (2 * n - 2);
    if(offset==0)
        offset = 1;

    while (count < len) {
        int pos = crow + (j / 2 + j % 2) * offset - (2 * crow) * (j % 2);
        if (pos >= len) {
            j = 0;
            crow++;
            continue;
        }
        r[count] = s[pos];
        count++;
        j += 1 + (crow == 0 || crow == n - 1);
    }
    r[len]='\0';
    return r;
}