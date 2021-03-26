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
	struct linkedlist_iter_s *iter;

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
		;
	, linkedlist_size(l) == 1, "linkedlist_size(l) == 1"
	);
	TEST(
		linkedlist_clear(l);
	, linkedlist_size(l) == 0, "linkedlist_clear(l), len == 0"
	);
	TEST(
		linkedlist_free(l);
	, l, "linkedlist_free(l)"
	);

	l = linkedlist_init();
	TIME(
		for (i = 0; i < 100000; ++i)
			linkedlist_add(l, &i);
	, "100,000 element insertion", 1
	);
	TIME(
		linkedlist_get(l, 0);
	, "access first element", 100
	);
	TIME(
		linkedlist_get(l, 50000);
	, "access 50,000th element", 100
	);
	TIME(
		linkedlist_get(l, 99999);
	, "access last element", 100
	);
	TIME(
		for (i = 0; i < 100000; ++i)
			linkedlist_get(l, i);
	, "access all elements via. linkedlist_get", 100
	);
	i = 0;
	TIME(
		iter = linkedlist_iter_begin(l);
		while (linkedlist_iter_hasnext(iter))
		{
			linkedlist_iter_next(&iter);
			++i;
		}
	, "access all elements via. forward iterator", 100
	);
	TEST(
		;
	, i == 100000 * 100, "iterator visited all elements"
	);
	i = 0;
	TIME(
		iter = linkedlist_iter_end(l);
		while (linkedlist_iter_hasprev(iter))
		{
			linkedlist_iter_prev(&iter);
			++i;
		}
	, "access all elements via. backward iterator", 100
	);
	TEST(
		;
	, i == 100000 * 100, "iterator visited all elements"
	);
	TIME(
		for (i = 0; i < 100000; ++i)
			linkedlist_remove(l, 0);
	, "100,000 element deletion", 1
	);
	linkedlist_free(l);
	return EXIT_SUCCESS;
}

