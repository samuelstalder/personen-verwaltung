#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include "list.h"

int person_compare(const person_t *a, const person_t *b) {

	int first_arg = strcmp(a->name, b->name);
	int second_arg = strcmp(a->first_name, b->first_name);
	int third_arg = 0;
	if (a->age > b->age) {third_arg = 1;}
	else if(a->age < b->age) {third_arg = -1;}

	if(first_arg == 0 && second_arg == 0 && third_arg == 0) {return 0;}

	if(first_arg != 0) {
		return first_arg;
	} else {
		if(second_arg != 0) {
			return second_arg;
		} else {
			if(third_arg != 0) {
				return third_arg;
			}
		}
	}
	return 0;
}