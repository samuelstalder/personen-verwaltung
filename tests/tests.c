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
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <assert.h>
#include <CUnit/Basic.h>
#include "test_utils.h"
#include "person.h"
#include "list.h"


#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief alias for EXIT_SUCCESS
#define OK   EXIT_SUCCESS
/// @brief alias for EXIT_FAILURE
#define FAIL EXIT_FAILURE

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

#define TRACE_INDENT "\n                " ///< allow for better stdout formatting in case of error

// setup & cleanup
static int setup(void)
{
    remove_file_if_exists(OUTFILE);
    remove_file_if_exists(ERRFILE);
    return 0; // success
}

static int teardown(void)
{
    // Do nothing.
    // Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
    return 0; // success
}

// tests
static void test_person_compare(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	person_t p1;
	strcpy(p1.name, "Stalder");
	strcpy(p1.first_name, "Samuel");
	p1.age = 21;

	person_t p2;
	strcpy(p2.name, "Stalder");
	strcpy(p2.first_name, "Elias");
	p2.age = 24;
	
	int res = person_compare(&p1, &p2);
	printf("test_person_compare %d\n", res);
	// act
	//CU_FAIL("missing test");
	
	// assert
	CU_ASSERT_TRUE(res > 0);

	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_insert(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	node_t *ancher = NULL;
	ancher = (node_t *) malloc(sizeof(node_t));

	person_t p1;
	strcpy(p1.name, "Stalder");
	strcpy(p1.first_name, "Samuel");
	p1.age = 21;

	list_insert(ancher, p1);
	printf("test_list_insert %s\n", ancher->next->content.first_name);
	// act
	//CU_FAIL("missing test");
	
	// assert
	int res = strcmp(ancher->next->content.first_name, "Samuel");
	CU_ASSERT_EQUAL(res, 0);
	
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_remove(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	node_t *ancher = NULL;
	ancher = (node_t *) malloc(sizeof(node_t));

	person_t p1;
	strcpy(p1.name, "Stalder");
	strcpy(p1.first_name, "Samuel");
	p1.age = 21;
	list_insert(ancher, p1);

	person_t p2;
	strcpy(p2.name, "Stalder");
	strcpy(p2.first_name, "Elias");
	p2.age = 24;
	list_insert(ancher, p2);


	list_remove(ancher, p2);

	// act
	//CU_FAIL("missing test");
	
	// assert
	CU_ASSERT_EQUAL(ancher->next->next, NULL);
	
	// END-STUDENTS-TO-ADD-CODE
}

static void test_list_clear(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	// arrange
	node_t *ancher = NULL;
	ancher = (node_t *) malloc(sizeof(node_t));

	person_t p1;
	strcpy(p1.name, "Stalder");
	strcpy(p1.first_name, "Samuel");
	p1.age = 21;
	list_insert(ancher, p1);

	person_t p2;
	strcpy(p2.name, "Stalder");
	strcpy(p2.first_name, "Elias");
	p2.age = 24;
	list_insert(ancher, p2);

	list_clear(ancher);

	// act
	//CU_FAIL("missing test");
	
	// assert
	CU_ASSERT_EQUAL(ancher->next, NULL);
	
	// END-STUDENTS-TO-ADD-CODE
}

/**
 * @brief Registers and runs the tests.
 * @returns success (0) or one of the CU_ErrorCode (>0)
 */
int main(void)
{
    // setup, run, teardown
    TestMainBasic("lab test", setup, teardown
                  , test_person_compare
                  , test_list_insert
                  , test_list_remove
                  , test_list_clear
                  );
}
