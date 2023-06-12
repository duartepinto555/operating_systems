#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char* argv[]) {
    FILE *fp;
    char* flag;
    char c;
    if (argc > 3 || argc < 2) {
        fprintf(stderr, "%s usage: %s file [flag]\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }
    if ((fp=fopen(argv[1],"r"))==NULL) {
        fprintf(stderr, "Error opening the file \"%s\"\n",argv[1]);
        return EXIT_FAILURE;
    }

    flag=argv[2];
    if (flag == NULL) {
        while ((c=fgetc(fp))!=EOF){
            printf("%c",c);
        }
        printf("\n");
        return EXIT_SUCCESS;
    }
    if (strcmp(flag,"-l")==0) {
        while ((c=fgetc(fp))!=EOF) {
            printf("%c",tolower(c));
        }
        printf("\n");
        return EXIT_SUCCESS;
    }
    else if (strcmp(flag,"-u")==0) {
        while ((c=fgetc(fp))!=EOF) {
            printf("%c",toupper(c));
        }
        printf("\n");
        return EXIT_SUCCESS;
    }
    else {
        while ((c=fgetc(fp))!=EOF){
            printf("%c",c);
        }
        printf("\n");
        return EXIT_SUCCESS;
    }

}