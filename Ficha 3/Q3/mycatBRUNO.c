#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
  FILE* f;
  char v[1000000];

  f= fopen("mystring.c","r");
  struct stat info;
  int ret = lstat("mystring.c",&info);

  int count = info.st_size;

  fread(v,1000000,1,f);

  for(int i=0;i<1000000;i++)
    printf("%c",v[i]);

  fclose(f);

  return 0;
}
