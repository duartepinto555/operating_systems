lib:
	gcc -c vector.c
	ar -rc libvector.a vector.o
	ar -t libvector.a
	make example
example:
	gcc -Wall use_vector.c -o use_vector -L . -lvector -lm
	./use_vector
