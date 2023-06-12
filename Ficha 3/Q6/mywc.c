#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int countChar (FILE* f) {
    int count = 0;
    char c;
    while((c=fgetc(f))!=EOF){
        count++;
    }
    return count;
}

int countWords (FILE* f) {
    int count = 0;
    int i = 0;
    char c;
    while((c=fgetc(f))!=EOF){
        i++;
        if (c==' '){
            count++;
        }
    }
    if (i!=0){
        count++;
    }
    return count;
}

int countLines (FILE* f) {
    int count = 0;
    char c;
    while((c=fgetc(f))!=EOF){
        if (c=='\n')
            count++;
    }
    return count;
}


int main(int argc, char* argv[]) {
    FILE* f;
    int count = 0;
    if (argv[1][0] == '-'){
        f = fopen(argv[2],"r");
        if (argv[1][1] == 'c') {
            printf("%d", countChar(f));
            return 0;
        }

        else if (argv[1][1] == 'w'){
            printf("%d", countWords(f));
            return 0;
        }

        else if (argv[1][1] == 'l'){
            printf("%d", countLines(f));
            return 0;
        }

        else{
            printf("Error, flag not found!\n");
            return 0;
        }
    }
    else {
        f = fopen(argv[1], "r");
        printf("%d", countChar(f));
        return 0;
        }
}