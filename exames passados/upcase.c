#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE   1024
 
int main(int argc, char* argv[]) {

  /* check if 1 args available */
  if (argc != 3) {
    printf("usage: ./upcase file1 file2\n");
    return EXIT_FAILURE;
  }

  /* check if argv[1] can be opened and is readable */
  FILE* fp = fopen(argv[1], "r");
  if(fp == NULL) {
    printf("%s: cannot open %s\n", argv[0], argv[1]);
    return EXIT_FAILURE;
  }

  FILE* fp2 = fopen(argv[2], "w");
  if (fp2 == NULL) {
    printf("%s: cannot open %s\n", argv[0], argv[1]);
    return EXIT_FAILURE;
  }

  char buf[BUFFER_SIZE];
  int nchars;
  /* read file and print it to stdout */
  while( (nchars=fread(buf, sizeof(char), BUFFER_SIZE, fp)) != 0) {
    int i;
    for (i=0; i<nchars; i++) {
	buf[i] = toupper(buf[i]);
    }
    fwrite(buf, sizeof(char), nchars, fp2);  
  }

  /* close file */
  fclose(fp);
  return EXIT_SUCCESS;
}