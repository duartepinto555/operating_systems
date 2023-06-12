#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define MAX_ARGS 100
int main(int argc, char* argv[]) {

    char buf[1024];
    char* args[MAX_ARGS];
    pid_t pid;

    /* do this until you get a ^C or a ^D */
    for( ; ; ) {
            
        /* give prompt, read command and null terminate it */
        fprintf(stdout, "$ ");  //writes "$ " in the file "stdout" (this means the "output" terminal)

        if((args[0] = fgets(buf, sizeof(buf), stdin)) == NULL)  // gets the command in "stdin" (input terminal) and stores it in buf
            break;
        //printf("%s\n",command);
        args[0][strlen(buf) - 1] = '\0';    // ultimo caracter do "command" e um "\n" ou semelhante
        args[0] = strtok(args[0], " ");
        int i=1;
        while ((args[i] = strtok(NULL," ")) != NULL) {
            i++;
        }

        /* call fork and check return value */
        if((pid = fork()) < 0) {
            fprintf(stderr, "%s: can't fork command: %s\n", argv[0], strerror(errno));
            continue;

        } else if(pid == 0) {
            /* child */
            execvp(args[0], args);
            /* if I get here "execlp" failed */
            fprintf(stderr, "%s: couldn't exec %s: %s\n",argv[0], args[0], strerror(errno));
            /* terminate with error to be caught by parent */
            exit(EXIT_FAILURE);
        }

        /* shell waits for command to finish before giving prompt again */
        if ((pid = waitpid(pid, NULL, 0)) < 0)
            fprintf(stderr, "%s: waitpid error: %s\n", argv[0], strerror(errno));
    }
    exit(EXIT_SUCCESS);
}
