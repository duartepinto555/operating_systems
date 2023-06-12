#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <utime.h>

int main(int argc, char* argv[]) {
    struct stat info;

    int fd = open(argv[1], O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (lstat(argv[1], &info) == -1) {      // takes the info to var info
        return EXIT_FAILURE;  
    }

    if (utime(argv[1], NULL) == -1) {       // Sets the date to 2nd argument (NULL = current date)
        fprintf(stderr, "Could not update the date of %s", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}