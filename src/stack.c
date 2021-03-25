/*
 * stack.c
 * Stack implementation.
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 25/03/2021
 */

#include "stack.h"

struct stack_s *
stack_init()
{
	return linkedlist_init();
}

void
stack_free(struct stack_s *s)
{
	linkedlist_free(s);
	return;
}

void *
stack_push(struct stack_s *s,
           void *val)
{
	return linkedlist_add(s, val);
}

void *
stack_pop(struct stack_s *s)
{
	if (!s || s->len == 0)
		return NULL;
	return linkedlist_remove(s, s->len - 1);
}

void
stack_clear(struct stack_s *s)
{
	linkedlist_clear(s);
	return;
}

void *
stack_peek(struct stack_s *s)
{
	if (!s || s->len == 0)
		return NULL;
	return linkedlist_get(s, s->len - 1);
}

int
stack_search(struct stack_s *s,
             void *val,
             size_t *i)
{
	int ret;
	if (!s || s->len == 0)
		return 0;
	ret = linkedlist_search(s, val, i);
	if (ret)
		*i = s->len - 1 - *i;
	return ret;
}

size_t
stack_size(struct stack_s *s)
{
	if (!s)
		return 0;
	return s->len;
}

int
stack_empty(struct stack_s *s)
{
	if (!s)
		return 1;
	return s->len == 0;
}

