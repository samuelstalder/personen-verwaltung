/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "person.h"
#include "list.h"

#define INPUT_LENGTH 25
#define INPUT_AGE_LENGTH 3

void end();
int is_correct_input(char name[30], char first_name[30], char age_as_chars[3]);

static int is_running = 1;

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
int main(int argc, char* argv[])
{
	// BEGIN-STUDENTS-TO-ADD-CODE

	node_t *ancher = NULL;
	ancher = (node_t *) malloc(sizeof(node_t));
	if (ancher == NULL) { return EXIT_FAILURE; }

	char input_name[INPUT_LENGTH];
	char input_first_name[INPUT_LENGTH];
	char input_age_as_chars[INPUT_AGE_LENGTH];
	//int input_age;
	person_t temp_person;
	while (is_running == 1) {
		printf("I(nsert), R(emove), S(how), C(lear), E(nd)\nEnter a value: ");
   		char c = getchar( );
		switch (c) {
			case 'I': //insert
				printf("Enter (name) (first name) (age): ");		
				scanf("%s %s %s", input_name, input_first_name, input_age_as_chars);
				if(is_correct_input(input_name, input_first_name, input_age_as_chars) == 1) {
					strncpy(temp_person.name, input_name, NAME_LEN);
					strncpy(temp_person.first_name, input_first_name, NAME_LEN);
					temp_person.age = atoi(input_age_as_chars);
					list_insert(ancher, temp_person);
					printf("Typed: %s %s %d\n", temp_person.name, temp_person.first_name, temp_person.age);
				}							
				break;
			case 'R': //remove
				printf("Enter (name) (first name) (age): ");		
				scanf("%s %s %s", input_name, input_first_name, input_age_as_chars);
				if(is_correct_input(input_name, input_first_name, input_age_as_chars) == 1) {
					strncpy(temp_person.name, input_name, NAME_LEN);
					strncpy(temp_person.first_name, input_first_name, NAME_LEN);
					temp_person.age = atoi(input_age_as_chars);
					list_remove(ancher, temp_person);
					printf("Typed: %s %s %d\n", temp_person.name, temp_person.first_name, temp_person.age);
				}
				break;
			case 'S': //show
				show_list(ancher);
				break;
			case 'C': //clear
				list_clear(ancher);
				printf("All removed\n");
				break;
			case 'E': //end
				end();
				break;
			case '\n':
				break;		
			default:
				printf("Didn't found this key word\n");
				break;
		}
	}    
	// END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}

void end() {
	is_running = 0;
}

int is_correct_input(char name[25], char first_name[25], char age_as_chars[3]) {
	int is_correct = 1;

	if(strlen(name) >= 19) {
		printf("Name is too long\n");
		is_correct = 0;
	}
	if(strlen(first_name) >= 19) {
		printf("First name is too long\n");
		is_correct = 0;
	}
	if(isdigit(age_as_chars[0]) == 0 && isdigit(age_as_chars[1]) == 0 && isdigit(age_as_chars[2]) == 0) {
		printf("Age is not a number\n");
		is_correct = 0;
	}

	//0: false
	return is_correct;
}

