#include <stdio.h>
#include <stdlib.h>

int* get_int() {
    int* p = (int*)malloc(sizeof(int));
    *p = 2;
    return p;
}

int use_int(int *p){
    int j = 3;
    return j + *p;
}

int main() {
    int* p = get_int();
    printf("integer = %d\n", *p);
    int k = use_int(p);
    printf("integer = %d\n", k);
    return 0;
}