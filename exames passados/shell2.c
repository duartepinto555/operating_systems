#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int main(int argc, char* argv[]) {
  pid_t pid;
  char* command;
  char buf[1024];
  
  signal(SIGINT, SIG_IGN);
  for ( ; ; ) {
    fprintf(stdout, "$");
    command = fgets(buf, 1024, stdin);
    command[strlen(buf) - 1] = '\0';
    if (strcmp(command,"quit") == 0) {
      printf("Quitting process...\n");
      break;
    }

    /* fork a child process */
    if ((pid = fork()) < 0 ) {
      perror("main@fork");
      return EXIT_FAILURE;
    }
    else if (pid == 0) {
      /* child process */
      if (execlp(command, command,NULL) < 0) {
        perror("main@execlp");
        return EXIT_FAILURE;
      }
    }
    else {
      /* parent process */
      if (waitpid(pid, NULL, 0) < 0) {
        perror("main@waitpid");
        return EXIT_FAILURE;
      }
    }
  }
  return EXIT_SUCCESS;
}