#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h> // ntohl
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "syntax : %s <file1> [<file2>...]\n", argv[0]);
        return 1;
    }

    uint32_t sum = 0;

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "rb");
        if (fp == NULL) {
            fprintf(stderr, "cannot open file: %s\n", argv[i]);
            return 1;
        }

        uint32_t be = 0;              
        size_t n = fread(&be, 1, 4, fp);
        fclose(fp);

        if (n != 4) {
            fprintf(stderr, "file is too small (need 4 bytes): %s\n", argv[i]);
            return 1;
        }

        uint32_t v = ntohl(be);       
        if (i > 1) printf(" + ");
        printf("%u(0x%08x)", v, v);
        sum += v;                     
    }

    printf(" = %u(0x%08x)\n", sum, sum);
    return 0;
}

