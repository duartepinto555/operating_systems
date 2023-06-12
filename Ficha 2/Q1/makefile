lib:
	gcc -c complex.c 
	ar -rc libcomplex.a complex.o
	ar -t libcomplex.a
	make example
example:
	gcc -Wall use_complex.c -o use_complex -L . -lcomplex -lm
	./use_complex
