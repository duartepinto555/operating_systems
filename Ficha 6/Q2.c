#include <sys/wait.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define SOCK_PARENT 0
#define SOCK_CHILD 1

#define DATA0 "In every walk with nature..."
#define DATA1 "...one receives far more than he seeks."
/* by John Muir */

int main(int argc, char* argv[]) {
    int sockets[2], filefp, rbytes;
    char buf[1024];
    pid_t pid;

    if ( (filefp = open(argv[1], O_RDONLY)) < 0 ) {
        printf("could not open file <%s>" , argv[1]);
        return EXIT_FAILURE;
    }

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0) {
        perror("opening stream socket pair");
        exit(1);
    }

    if ((pid = fork()) < 0) {
        perror("fork");
        return EXIT_FAILURE;
    }
    else if (pid > 0) {
        /* this is the parent */
        close(sockets[SOCK_CHILD]);
        // reading from file and writing to socket 
        while ( (rbytes = read(filefp, buf, sizeof(buf))) != 0) {
            write(sockets[SOCK_PARENT], buf, rbytes);
            if ( (rbytes = read(sockets[SOCK_PARENT], buf, sizeof(buf))) != 0)
                write(STDOUT_FILENO, buf, rbytes);
        }
        close(sockets[SOCK_PARENT]);
        /* wait for child and exit */
        if (waitpid(pid, NULL, 0) < 0) {
            perror("did not catch child exiting");
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }

    else {
        /* this is the child */
        close(sockets[SOCK_PARENT]);
        while ( (rbytes = read(sockets[SOCK_CHILD], buf, sizeof(buf))) != 0 ) {
            for (int i=0; i<rbytes; i++) 
                *(buf + i) = toupper( *(buf + i) );
            write(sockets[SOCK_CHILD], buf, rbytes);
        }
        close(sockets[SOCK_CHILD]);
        /* leave gracefully */
        return EXIT_SUCCESS;

    }
    return EXIT_SUCCESS;
}