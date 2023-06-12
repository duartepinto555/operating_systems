#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
  char s[strlen(argv[1])+1];
  int i=0;
  for(i=0;i<strlen(argv[1]);i++){
    int a = argv[1][i];
    int b = tolower(a);
    s[i]=b;
  }
  s[i]='\0';
  printf("%s\n",s);
}
