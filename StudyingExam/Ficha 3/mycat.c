#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {
    int i=1;
    FILE *fp;
    while (argv[i]) {
        if((fp = fopen(argv[i],"rt")) == NULL) {
            fprintf(stderr,"$ Failed to open \"%s\".\n", argv[i]);
            return EXIT_FAILURE;
        }
        char c;
        while ((c=fgetc(fp))!=EOF) {
            printf("%c",c);
        }
        printf("\n");
        i++;
    }
    return EXIT_SUCCESS;
}
