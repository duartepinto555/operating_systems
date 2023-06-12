#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 100

//o pedido era diferente, mas aqui dá as poicoes em que a palavra aparece.
int main(int argc, char* argv[]){
    FILE* f = fopen(argv[2],"r");
    int size = 0;
    char c;
    char* ficheiro = (char*) malloc(MAX_STR_SIZE);

    while ((c=fgetc(f)) != EOF){
        ficheiro[size] = c;
        size++;
    }
    
    int count = 0;
    while (count<size){
        int i=0;
            while(i<sizeof(argv[1])){
                if (ficheiro[count+i] != argv[1][i]){
                    break;
                }
                i++;
            }
            if (i==sizeof(argv[1])){
                printf("[%d:%d]\n",count, count+sizeof(argv[1]));
            }
            count++;
    }
    return 0;
}