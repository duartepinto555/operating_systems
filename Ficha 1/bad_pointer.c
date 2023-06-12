#include <stdio.h>
#include <stdlib.h>

int* get_int() {
    int i = 2;
    return &i;
}


int use_int(int *p) {
    int j = 3;
    return j + *p;
}


int main() {
    int* p = get_int();
    printf("integer = %p\n", p);
    printf("integer = %d\n", *p);
    return 0;
}
