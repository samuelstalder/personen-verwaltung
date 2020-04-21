#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include "list.h"

int person_compare(const person_t *a, const person_t *b) {

	int first_arg = strncmp(a->name, b->name, NAME_LEN);
	int second_arg = strncmp(a->first_name, b->first_name, NAME_LEN);
	int third_arg = a->age - b->age; //difference between age a und age b

	//printf("a: %s %s %d\n", a->name, a->first_name, a->age);
	//printf("b: %s %s %d\n", b->name, b->first_name, b->age);

	if(first_arg == 0 && second_arg == 0 && third_arg == 0) {return 0;}

	
	if(first_arg != 0) {
		//printf("----person_compare  %d--\n", first_arg);
		return first_arg;
	} else {
		if(second_arg != 0) {
			//printf("----person_compare  %d--\n", second_arg);
			return second_arg;
		} else {
			if(third_arg != 0) {
				//printf("----person_compare  %d--\n", third_arg);
				return third_arg;
			}
		}
	}


	return 0;
}