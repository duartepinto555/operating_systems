#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int next_block_size(int count, int buffer_size) {
  /*Se count>=buffer_size, é retornado o valor do buffer_size,
  caso contrário é retornado o resto da divisão de count por
  buffer_size */
  return (count >= buffer_size)? buffer_size: count % buffer_size;
  /*Não percebo bem a sintaxe...*/
}

int main(int argc, char* argv[]) {
  for(int i=1;i<argc;i++){
    /* check if file can be opened and is readable */
    int fd = open(argv[i], O_RDONLY);

    if (fd == -1) {
      printf("error: cannot open %s\n", argv[i]);
      printf("\n---------------------------------------------\n\n");
      continue;
    }

    /* get the file size */
    struct stat info;
    int ret = lstat(argv[i], &info);
    if (ret == -1) {
      printf("error: cannot stat %s\n", argv[i]);
      continue;
    }

    /* print the contents in blocks */
    int count = info.st_size;
    char buffer[BUFFER_SIZE];
    while (count != 0) {
      int bytesin = read(fd, buffer, next_block_size(count, BUFFER_SIZE));
      /*bytesin = nº de bytes lidos
      Não sei bem porquê, mas sempre que a função read é chamada,
      o ficheiro não é lido desde início, mas sim a partir de onde
      ficou por ler desde a sua última chamada*/
      count -= bytesin;
      write(STDOUT_FILENO, buffer, bytesin);
    }

    /* close file */
    close(fd);
    if(i!= argc-1)
      printf("\n---------------------------------------------\n\n");
  }
  return EXIT_SUCCESS;
}
