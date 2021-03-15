/*
 * linkedlist.c
 * Linked list implementation.
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 15/03/2021
 */

#include "linkedlist.h"

struct linkedlist_s *
linkedlist_init()
{
	struct linkedlist_s *l = (struct linkedlist_s *)
	                         malloc(sizeof(struct linkedlist_s));
	l->head = NULL;
	l->tail = NULL;
	l->len = 0;
	return l;
}

void
linkedlist_free(struct linkedlist_s *l)
{
	struct node_s *n, *tmp;
	if (!l)
		return;
	n = l->head;
	while (n)
	{
		tmp = n->next;
		free(n);
		n = tmp;
	}
	free(l);
	return;
}

void *
linkedlist_add(struct linkedlist_s *l,
               void *val)
{
	struct node_s *n;
	if (!l)
		return NULL;
	n = (struct node_s *) malloc(sizeof(struct node_s));
	n->last = l->tail;
	if (n->last)
		n->last->next = n;
	n->next = NULL;
	n->ptr = val;
	if (!l->tail)
		l->head = n;
	l->tail = n;
	l->len++;
	return val;
}

void *
linkedlist_remove(struct linkedlist_s *l,
                  size_t i)
{
	struct node_s *n;
	void *ptr;
	if (!l || i >= l->len)
		return NULL;
	n = l->head;
	while (i-- > 0)
		n = n->next;
	if (l->head == n)
		l->head = n->next;
	else
		n->last->next = n->next;
	if (l->tail == n)
		l->tail = n->last;
	else
		n->next->last = n->last;
	l->len--;
	ptr = n->ptr;
	free(n);
	return ptr;
}

void *
linkedlist_get(struct linkedlist_s *l,
               size_t i)
{
	struct node_s *n;
	if (!l || i >= l->len)
		return NULL;
	n = l->head;
	while (i-- > 0)
		n = n->next;
	return n->ptr;
}

size_t
linkedlist_size(struct linkedlist_s *l)
{
	if (!l)
		return 0;
	return l->len;
}

