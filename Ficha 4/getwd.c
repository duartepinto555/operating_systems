#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 1) {
        (void)fprintf(stderr, "usage: %s\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("%s", getwd(argv[0]));
    return EXIT_SUCCESS;
}