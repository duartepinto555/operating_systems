lib:
	gcc -c matrix.c 
	ar -rc libmatrix.a matrix.o
	ar -t libmatrix.a
	make example
example:
	gcc -Wall use_matrix.c -o use_matrix -L . -lmatrix -lm
	./use_matrix
