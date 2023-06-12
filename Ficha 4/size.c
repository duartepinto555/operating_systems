#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    struct stat info;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int size = 0;
    int bsize = 0;
    char buffer[200];
    for (int i=1; i<argc; i++) {        // ADICIONADO PARA RESOLUCAO EX
        if (lstat(argv[i], &info) == -1) {
            fprintf(stderr, "fsize: Can't stat %s\n", argv[1]);
            return EXIT_FAILURE;
        }
        size += (int)info.st_size;
        bsize += (int)info.st_blocks;

        //printf("Last update %s: %s, owner: %s", argv[i], formatdate(buffer, info.st_mtim), info.st_uid);
        printf("Last update %s: %ld, owner: %ld", argv[i], info.st_mtim.tv_nsec , (long) info.st_uid);
        
    }
    printf("Total size: %d bytes, disk_blocks: %d\n", size, bsize);
    return EXIT_SUCCESS;
}