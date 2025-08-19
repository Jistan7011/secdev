// dump-bytes.c
#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "syntax: %s <file1> [<file2>...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        const char *path = argv[i];
        FILE *f = fopen(path, "rb");   // 바이너리 모드로 열기
        if (!f) { perror(path); return 1; }

        printf("==> %s <==\n", path);

        unsigned char buf[4096];
        size_t n, count = 0;
        while ((n = fread(buf, 1, sizeof(buf), f)) > 0) {
            for (size_t j = 0; j < n; ++j) {
                printf("%02x", buf[j]);           // 2자리 16진수
                if (++count % 16 == 0) putchar('\n'); // 16바이트마다 개행
                else putchar(' ');
            }
        }
        if (ferror(f)) { perror("fread"); fclose(f); return 1; }
        if (count % 16 != 0) putchar('\n');        // 마지막 줄 정리
        fclose(f);
    }
    return 0;
}

