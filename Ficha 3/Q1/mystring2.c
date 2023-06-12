#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR_SIZE 64

int main(int argc, char* argv[]) {
  char *s;
  int count=0;
  s=argv[2];

  while(s!=NULL){
    s=strstr(s,argv[1]);
    if(s!=NULL){
      count++;
      s++;
    }
  }
  printf("%d\n",count);
}
