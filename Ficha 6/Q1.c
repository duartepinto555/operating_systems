#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>
#include <fcntl.h>

#define READ_END 0
#define WRITE_END 1
#define LINESIZE 256

int main(int argc, char* argv[]) {
    int   rbytes, filefd, pipefd[2];
    char  line[LINESIZE];
    pid_t pid;

    if ( (filefd = open(argv[1], O_RDONLY)) < 0 ){
        printf("couldn't open file '%s'" , argv[1]);
        return EXIT_FAILURE;
    }

    if (pipe(pipefd) < 0) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }

    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(EXIT_FAILURE);
    }

    else if (pid > 0) {
        /* parent */
        close(pipefd[READ_END]);
        //printf("buf -> %s\n" , buf);
        while( (rbytes = read(filefd, line, LINESIZE)) != 0 )
            write(pipefd[WRITE_END], line, LINESIZE);
        close(filefd);
        close(pipefd[WRITE_END]);
        /* wait for child and exit */
        if ( waitpid(pid, NULL, 0) < 0) {
            fprintf(stderr, "Parent: Cannot wait for child: %s\n", strerror(errno));
        }
        exit(EXIT_SUCCESS);
    }
    
    else {
        /* child */
        close(pipefd[WRITE_END]);
        while ((rbytes = read(pipefd[READ_END], line, LINESIZE)) != 0 ) {
            if (rbytes<0)
                fprintf(stderr, "Child: Unable to read from pipe: %s\n", strerror(errno));
            write(STDOUT_FILENO, line, rbytes);   
        }
        close(pipefd[READ_END]);
        return EXIT_SUCCESS;
    }
}