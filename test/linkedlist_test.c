/*
 * linkedlist_test.c
 * Linked list test suite.
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 15/03/2021
 */

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

#define FAIL(x,y) if (!(x)) {\
                      fprintf(stdout, "\rFAILURE: %s\n", y);\
                      return EXIT_FAILURE;\
                  } else {\
                      fprintf(stdout, "\rSUCCESS: %s\n", y);\
                  }
#define TEST(x,y,z) fprintf(stdout, "TEST: %s", z); fflush(stdout); x FAIL(y,z)

int
main(int argc,
     char **argv)
{
	int i;
	char *s;
	void *ptr;
	struct linkedlist_s *l;

	(void) argc;
	(void) argv;
	i = 71;
	s = "AABBCCDDEE";

	TEST(
		l = linkedlist_init();
	, l, "linkedlist_init() != NULL"
	);
	TEST(
		ptr = linkedlist_add(l, &i);
	, ptr == (void *) &i, "linkedlist_add(l, &i) == &i"
	);
	TEST(
		ptr = linkedlist_add(l, s);
	, ptr == (void *) s, "linkedlist_add(l, s) == s"
	);
	TEST(
		;
	, linkedlist_size(l) == 2, "linkedlist_size(l) == 2"
	);
	TEST(
		ptr = linkedlist_get(l, 1);
	, ptr == (void *) s, "linkedlist_get(l, 1) == s"
	);
	TEST(
		ptr = linkedlist_remove(l, 0);
	, ptr == (void *) &i, "linkedlist_remove(l, 0) == &i"
	);
	TEST(
		ptr = linkedlist_remove(l, 0);
	, ptr == (void *) s, "linkedlist_remove(l, 0) == s"
	);
	TEST(
		;
	, linkedlist_size(l) == 0, "linkedlist_size(l) == 0"
	);
/*	TEST(

	);
*/	return EXIT_SUCCESS;
}

