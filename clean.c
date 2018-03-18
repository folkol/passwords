#include <stdio.h>

#define BUF_SIZE 1024

int main() {
    char buf[BUF_SIZE];
    int lineno = 0;
    while(fgets(buf, BUF_SIZE, stdin)) {
        int ascii = 1;
        for(char *p = buf; *p; p++) {
            if(*p < 0 || *p > 127) {
                ascii = 0;
                break;
            }
        }
        if(ascii) {
            printf("%s", buf);
        } else {
            fprintf(stderr, "Stripping [%d]: %s", lineno, buf);
        }
        lineno++;
    }
}

