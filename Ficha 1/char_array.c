#include <stdio.h>

int main() {
    int i;
    int* p;
    char msg[] = "Hello World";
    for (i = 0; i < sizeof(msg); i++){
        printf("%c <--> %c\n", msg[i], *(msg + i));
    }
    printf("%c", *(msg));
    return 0;
}

/*
A variavel msg comporta-se como se fosse um endereco
Cada incremento de i corresponde a 8 bits = 1 byte
*/