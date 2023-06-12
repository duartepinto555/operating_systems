#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {

	char *s = argv[2];
	int count = 0;
	while (s!=NULL) {
		count ++;
		s++;
		s = strstr(s,argv[1]);
	}
	printf("%d\n",count);
}
