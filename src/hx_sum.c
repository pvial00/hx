#include "hx.c"
#include <unistd.h>

int main(int argc, char *argv[]) {
    unsigned char *password;
    unsigned char *salt = "DarkCastleSui";
    unsigned char D[32] = {0};
    unsigned char *buf;
    char digest[32*2+1];
    FILE *infile;
    if (argc != 2) {
        printf("hxsum <input file>\n");
        exit(1);
    }
    if (access(argv[1], F_OK) == -1 ) {
        printf("%s not found\n", argv[1]);
        exit(1);
    }
    infile = fopen(argv[1], "rb");
    fseek(infile, 0, SEEK_END);
    long long fsize = ftell(infile);
    fseek(infile, 0, SEEK_SET);
    buf = (unsigned char *)malloc(fsize);
    fread(buf, 1, fsize, infile);
    fclose(infile);
    hx_digest(buf, fsize, D, salt, 12);
    for (int x = 0; x < 32; x++) {
        sprintf(&digest[x*2], "%02x", D[x]);
    }
    printf("%s\n", digest);
}
