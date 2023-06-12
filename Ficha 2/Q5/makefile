lib:
	gcc -c list.c 
	ar -rc liblist.a list.o
	ar -t liblist.a
	make example
example:
	gcc -Wall use_list.c -o use_list -L . -llist -lm
	./use_list
