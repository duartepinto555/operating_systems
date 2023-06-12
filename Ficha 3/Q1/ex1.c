#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
	char* p1 = (char*)malloc(MAX_STR_SIZE * sizeof(char));

	int i=0;
	while(argv[1][i]) {
		p1[i] = tolower(argv[1][i]);
		i++;
	}
	printf("string = %s\n",p1);
	return EXIT_SUCCESS;
}
