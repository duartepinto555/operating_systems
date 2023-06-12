#include <stdio.h>

int main() {
    int i, j, *p, *q;
    i = 5;
    p = &i;
    printf("i=%d, p=%p, *p=%d\n", i, p, *p);
    *p = 7;
    printf("i=%d, p=%p, *p=%d\n", i, p, *p);
    j = 3;
    printf("i=%d, j=%d, p=%p, *p=%d\n", i, j, p, *p);
    p = &j;
    printf("i=%d, j=%d, p=%p, *p=%d\n", i, j, p, *p);
    q = p;
    printf("i=%d, j=%d, p=%p, *p=%d, q=%p, *q=%d\n", i, j, p, *p, q, *q);
    p = &i;
    printf("i=%d, j=%d, p=%p, *p=%d, q=%p, *q=%d\n", i, j, p, *p, q, *q);
    *q = 2;
    printf("i=%d, j=%d, p=%p, *p=%d, q=%p, *q=%d\n", i, j, p, *p, q, *q);
    return 0;
}