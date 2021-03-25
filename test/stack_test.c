/*
 * stack_test.c
 * Stack test suite.
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 25/03/2021
 */

#include <stdlib.h>

#include "common_test.h"
#include "stack.h"

int
main(int argc,
     char **argv)
{
	int i;
	char *s;
	void *ptr;
	size_t idx;
	struct stack_s *l;

	INIT();

	(void) argc;
	(void) argv;
	i = 71;
	s = "AABBCCDDEE";

	TEST(
		l = stack_init();
	, l, "stack_init() != NULL"
	);
	TEST(
		ptr = stack_push(l, &i);
	, ptr == (void *) &i, "stack_push(l, &i) == &i"
	);
	TEST(
		ptr = stack_push(l, s);
	, ptr == (void *) s, "stack_push(l, s) == s"
	);
	TEST(
		i = stack_empty(l);
	, i == 0, "stack_empty(l) == 0"
	);
	TEST(
		;
	, stack_size(l) == 2, "stack_size(l) == 2"
	);
	TEST(
		ptr = stack_peek(l);
	, ptr == (void *) s, "stack_peek(l) == s"
	);
	TEST(
		i = stack_search(l, &i, &idx);
	, i == 1 && idx == 1, "stack_search(l, i, &idx) == 1, idx == 0"
	);
	TEST(
		i = stack_search(l, s, &idx);
	, i == 1 && idx == 0, "stack_search(l, s, &idx) == 1, idx == 1"
	);
	TEST(
		i = stack_search(l, NULL, &idx);
	, i == 0, "stack_search(l, NULL, &idx) == 0"
	);
	TEST(
		ptr = stack_pop(l);
	, ptr == (void *) s, "stack_pop(l) == s"
	);
	TEST(
		ptr = stack_pop(l);
	, ptr == (void *) &i, "stack_pop(l) == &i"
	);
	TEST(
		;
	, stack_size(l) == 0, "stack_size(l) == 0"
	);
	TEST(
		i = stack_empty(l);
	, i == 1, "stack_empty(l) == 1"
	);
	TEST(
		stack_free(l);
	, l, "stack_free(l)"
	);

	l = stack_init();
	TIME(
		for (i = 0; i < 100000; ++i)
			stack_push(l, &i);
	, "100,000 element push"
	);
	TIME(
		for (i = 0; i < 100000; ++i)
			stack_pop(l);
	, "100,000 element pop"
	);
	stack_free(l);
	return EXIT_SUCCESS;
}

