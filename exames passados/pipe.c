#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define READ 0
#define WRITE 1
#define BUFFER_SIZE  256

int main(int argc, char* argv[]) {
  int   fd[2];
  pid_t pid;

  if (pipe(fd) < 0) {
    perror("main@pipe");
    exit(EXIT_FAILURE);
  }

  if ((pid = fork()) < 0) {
    perror("main@fork");
    exit(EXIT_FAILURE);
  }
  else if (pid > 0) {
    /* parent */
    char  buf1[] = "To be, or not to be, that is the question";

    close(fd[READ]);
    if (write(fd[WRITE], buf1, strlen(buf1)) < 0) {
      perror("main@write");
      return EXIT_FAILURE;
    }

    /* close pipe end */    
    close(fd[WRITE]);

    /* wait for child and exit */
    if ( waitpid(pid, NULL, 0) < 0) {
      perror("main@waitpid");
      return EXIT_FAILURE;
    }

    /* exit gracefully */    
    exit(EXIT_SUCCESS);
  }
  else {
    /* child */
    int nchars;
    char  buf2[BUFFER_SIZE];
    
    close(fd[WRITE]);
    if ( (nchars = read(fd[READ], buf2, BUFFER_SIZE)) < 0 ) {
      perror("main@read");
      return EXIT_FAILURE;
    }

    /* write message from parent */
    write(STDOUT_FILENO, buf2, nchars);

    /* close pipe end */
    close(fd[READ]);

    /* exit gracefully */
    exit(EXIT_SUCCESS);
  } 
}