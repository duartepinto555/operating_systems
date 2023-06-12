#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(int argc, char* argv[]) {
    FILE *f;
    char c;
	int i=1;
	while (argv[i]) {
		f=fopen(argv[i],"rt");
		while((c=fgetc(f))!=EOF){
			printf("%c",c);
		}
		i++;
		printf("\n");
		fclose(f);
	}
    return 0;
}