/*
 * compare_structure.c
 * Structure comparison suite.
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 26/03/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linkedlist.h"
#include "stack.h"

#define N 100000

#define RED    "\x1b[1;31m"
#define YELLOW "\x1b[1;33m"
#define GREEN  "\x1b[1;32m"
#define CYAN  "\x1b[1;36m"
#define BOLD  "\x1b[1m"
#define RESET  "\x1b[0m"

#define INIT() int clockiter; clock_t tic, toc;\
               double tmptime, besttime, worsttime, avgtime;
#define TIME(x,y,z) clockiter = 0;\
                    besttime = 0; worsttime = 0, avgtime = 0;\
                    while (clockiter++ < z) {\
                        tic = clock(); x toc = clock();\
                        tmptime = (double) (toc - tic) / CLOCKS_PER_SEC;\
                        avgtime += tmptime;\
                        if (clockiter == 1 || tmptime < besttime)\
                            besttime = tmptime;\
                        if (clockiter == 1 || tmptime > worsttime)\
                            worsttime = tmptime;\
                    }\
                    avgtime /= z;\
                	fprintf(stdout, BOLD "%*s" RESET "|%*fs|%*fs|%*fs\n",\
	                12, y, 10, besttime, 9, avgtime, 11, worsttime);

static
void
print_header(char *c)
{
	printf("\n" YELLOW "%*s" RESET
	       "|  " GREEN "best time" RESET
	       "|  " CYAN "avg time" RESET
	       "|  " RED "worst time" RESET "\n", 12, c);
	printf("------------|-----------|----------|------------\n");
	return;
}

static
void
test_insert(struct linkedlist_s *ll,
            struct stack_s *s)
{
	int i;

	INIT();

	i = 0;
	print_header("insert");
	TIME(
		linkedlist_add(ll, &i);
	, "linkedlist", N);
	TIME(
		stack_push(s, &i);
	, "stack", N);
	return;
}

static
void
test_remove(struct linkedlist_s *ll,
            struct stack_s *s)
{
	INIT();

	print_header("remove");
	TIME(
		linkedlist_remove(ll, rand() % ll->len);
	, "*linkedlist", N);
	TIME(
		stack_pop(s);
	, "stack", N);
	return;
}

static
void
test_access(struct linkedlist_s *ll,
            struct stack_s *s)
{
	INIT();

	print_header("access");
	TIME(
		linkedlist_get(ll, rand() % ll->len);
	, "*linkedlist", N);
	TIME(
		stack_peek(s);
	, "stack", N);
	return;
}

int
main(int argc,
     char **argv)
{
	struct linkedlist_s *ll;
	struct stack_s *s;
	time_t t;

	(void) argc;
	(void) argv;
	ll = linkedlist_init();
	s = stack_init();

	srand(time(&t));

	fprintf(stdout, "N = %d\n", N);
	fprintf(stdout, "* indicates random index\n");

	test_insert(ll, s);
	test_access(ll, s);
	test_remove(ll, s);

	linkedlist_free(ll);
	stack_free(s);

	return EXIT_SUCCESS;
}

