#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(int argc, char* argv[]) {
    FILE *f;
    char* out = (char*) malloc(sizeof(char)*sizeof(argv[2]));
    char c;
    int i = 0;
    if (argv[1][1] == 'u' && argv[1][0] == '-') {
        f=fopen(argv[2],"rt");
        while((c=fgetc(f))!=EOF){
            out[i] = toupper(c);
            i++;
        }
        out[i] = 0;
        printf("%s",out);
        fclose(f);
        return 0;
    }
    else if (argv[1][1] == 'l' && argv[1][0] == '-'){
        f=fopen(argv[2],"rt");
        while((c=fgetc(f))!=EOF){
            out[i] = tolower(c);
            i++;
        }
        out[i] = 0;
        printf("%s",out);
        fclose(f);
        return 0;
    }
    else {
        f=fopen(argv[1],"rt");
        while((c=fgetc(f))!=EOF){
            printf("%c",c);
        }
        fclose(f);
        return 0;
    }
}