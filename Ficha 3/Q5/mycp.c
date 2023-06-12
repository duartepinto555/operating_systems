#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(int argc, char* argv[]) {
    FILE *f;
    FILE *f2;
    char c[] = "";
    f=fopen(argv[1],"rt");
    f2=fopen(argv[2],"w");
    while((c[0]=fgetc(f))!=EOF){
        fwrite(c, 1, 1, f2);
    }
    fclose(f);
    fclose(f2);
    return 0;
}