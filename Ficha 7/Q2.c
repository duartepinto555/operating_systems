#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 10
int piper (char* arg) {
    const char s[2] = "|";

    char* cmd = strtok(arg, s);
    char* aux1 = (char*) malloc(sizeof(cmd));
    aux1 = cmd;
    cmd = strtok(NULL, s);

    char* aux2 = (char*) malloc(sizeof(cmd));
    aux2 = cmd;

    const char s1[2] = " ";


    char* cmd1[3];
    char* cmd2[3];

    cmd = strtok(aux1, s1);
    

    int i=0;
    while (cmd != NULL) {
        cmd1[i] = cmd;
        cmd = strtok(NULL, s);
        i++;
    }
    cmd1[i] = NULL;
    cmd = strtok(aux2, s);
    i=0;
    while (cmd != NULL) {
        cmd2[i] = cmd;
        cmd = strtok(NULL, s);
        i++;
    }
    cmd2[i] = NULL;

    

    int fd[2];
    pid_t pid;
    if (pipe(fd) < 0) {
        /* pipe error */
        fprintf(stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }
    if ((pid = fork()) < 0) {
        /* fork error */
        fprintf(stderr, "Fork failed.\n");
        return EXIT_FAILURE;
    }
    if (pid > 0) {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO); // stdout to pipe
        close(fd[1]);
        // parent writes to the pipe
        if (execvp(cmd1[0], cmd1) < 0) {
            /* exec error */
            fprintf(stderr, "Exec <%s> error.\n", cmd1[0]);
            return EXIT_FAILURE;
        }
    } 
    else {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO); // stdin from pipe
        close(fd[0]);
        if (execvp(cmd2[0], cmd2) < 0) {
            /* exec error */
            fprintf(stderr, "Exec <%s> error", cmd2[0]);
            return EXIT_FAILURE;
        }
    }
}

int main (int argc, char* argv[]) {
    return piper(argv[1]);
}