#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {

	if (strstr(argv[2], argv[1]) != NULL)
		printf("%s", strstr(argv[2],argv[1]));
	else {printf("%d\n", 0);}
	return EXIT_SUCCESS;
}

