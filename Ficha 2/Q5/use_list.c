#include <stdio.h>
#include <stdlib.h>

#include "list.c"


int main(int argc, char** argv) {
	list* l = list_new_random(10,20);
	list_print(l);
	printf("First: '%d' | Last: '%d' | Size: '%d'\n" , list_get_first(l),list_get_last(l),list_size(l));
	list_add_last(37, l);
	list_add_first(73,l);
	printf("First: '%d' | Last: '%d' | Size: '%d'\n" , list_get_first(l),list_get_last(l),list_size(l));
	list_remove_last(l);
	list_print(l);
	
}
