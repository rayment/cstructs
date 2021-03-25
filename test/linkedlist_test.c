/*
 * linkedlist_test.c
 * Linked list test suite.
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 15/03/2021
 */

#include <stdlib.h>

#include "common_test.h"
#include "linkedlist.h"

int
main(int argc,
     char **argv)
{
	int i;
	char *s;
	void *ptr;
	size_t idx;
	struct linkedlist_s *l;

	INIT();

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
		i = linkedlist_search(l, &i, &idx);
	, i == 1 && idx == 0, "linkedlist_search(l, i, &idx) == 1, idx == 0"
	);
	TEST(
		i = linkedlist_search(l, s, &idx);
	, i == 1 && idx == 1, "linkedlist_search(l, s, &idx) == 1, idx == 1"
	);
	TEST(
		i = linkedlist_search(l, NULL, &idx);
	, i == 0, "linkedlist_search(l, NULL, &idx) == 0"
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
	TEST(
		linkedlist_free(l);
	, l, "linkedlist_free(l)"
	);

	l = linkedlist_init();
	TIME(
		for (i = 0; i < 100000; ++i)
			linkedlist_add(l, &i);
	, "100,000 element insertion"
	);
	TIME(
		linkedlist_get(l, 0);
	, "find first element"
	);
	TIME(
		linkedlist_get(l, 50000);
	, "find 50,000th element"
	);
	TIME(
		linkedlist_get(l, 99999);
	, "find last element"
	);
	TIME(
		for (i = 0; i < 100000; ++i)
			linkedlist_remove(l, 0);
	, "100,000 element deletion"
	);
	linkedlist_free(l);
	return EXIT_SUCCESS;
}

