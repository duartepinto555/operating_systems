#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"

int main(int argc, char** argv) {

	matrix* M1 = matrix_new_random(5,5,0,10);
	matrix* M2 = matrix_new_random(5,5,0,10);
	matrix* M3 = matrix_new_random(5,5,0,10);
	matrix* M4 = matrix_new_random(5,5,0,10);
	matrix* M5 = matrix_new_random(5,5,0,10);


	printf("M1: \n");
	matrix_print(M1);
	printf("Primeiro elemento M1: %f\n", matrix_get(0,0,M1));
	printf("M2: \n");
	matrix_print(M2);
	printf("M3: \n");
	matrix_print(M3);
	printf("M4: \n");
	matrix_print(M4);
	printf("M5: \n");
	matrix_print(M5);

	printf("M2+M1 \n");
	matrix_print(matrix_add(M1,M2));
	printf("M3-M4\n");
	matrix_print(matrix_sub(M3,M4));
	printf("M5*M3\n");
	matrix_print(matrix_mul(M5,M3));
	printf("Transposta M5\n");
	matrix_print(matrix_trans(M5));



	return 0;
}
