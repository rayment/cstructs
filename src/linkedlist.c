/*
 * linkedlist.c
 * Linked list implementation.
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 15/03/2021
 */

#include "linkedlist.h"

static void
linkedlist_iter_calculate(struct linkedlist_s *l,
                          struct node_s **n,
                          size_t i,
                          int *dir)
{
	if (l->iter)
	{
		*dir = 1;
		*n = l->head;
		if (i < l->iterpos)
		{
			if (l->iterpos - i <= i)
			{
				*n = l->iter;
				*dir = -1;
			}
			else
			{
				l->iterpos = 0;
			}
		}
		else if (i > l->iterpos)
		{
			if (i - l->iterpos > l->len - i)
			{
				*n = l->tail;
				l->iterpos = l->len - 1;
				*dir = -1;
			}
			else
			{
				*n = l->iter;
			}
		}
	}
	else
	{
		*n = l->iter = l->head;
		l->iterpos = 0;
		*dir = 1;
	}
	return;
}

struct linkedlist_s *
linkedlist_init()
{
	struct linkedlist_s *l = (struct linkedlist_s *)
	                         malloc(sizeof(struct linkedlist_s));
	l->head = NULL;
	l->tail = NULL;
	l->iter = NULL;
	l->len = 0;
	l->iterpos = 0;
	return l;
}

void
linkedlist_free(struct linkedlist_s *l)
{
	if (!l)
		return;
	linkedlist_clear(l);
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
	int dir;
	struct node_s *n;
	void *ptr;
	if (!l || i >= l->len)
		return NULL;
	if (l->iter && i == l->iterpos)
	{
		n = l->iter;
	}
	else if (i == 0)
	{
		n = l->head;
	}
	else if (i == l->len - 1)
	{
		n = l->tail;
	}
	else
	{
		linkedlist_iter_calculate(l, &n, i, &dir);
		while (l->iterpos != i)
		{
			if (dir > 0)
				n = n->next;
			else if (dir < 0)
				n = n->last;
			l->iterpos += dir;
		}
		l->iter = n;
	}
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
	if (l->iter && i == l->iterpos)
	{
		if (n->last)
		{
			--l->iterpos;
			l->iter = n->last;
		}
		else if (n->next)
		{
			l->iter = n->next;
		}
		else
		{
			l->iter = NULL;
		}
	}
	else if (l->iter && i < l->iterpos)
	{
		--l->iterpos;
	}
	free(n);
	return ptr;
}

void
linkedlist_clear(struct linkedlist_s *l)
{
	struct node_s *n, *tmp;
	if (l->len == 0)
		return;
	n = l->head;
	while (n)
	{
		tmp = n->next;
		free(n);
		n = tmp;
	}
	l->head = NULL;
	l->tail = NULL;
	l->iter = NULL;
	l->iterpos = 0;
	l->len = 0;
	return;
}

void *
linkedlist_get(struct linkedlist_s *l,
               size_t i)
{
	int dir;
	struct node_s *n;
	if (!l || i >= l->len)
		return NULL;
	if (l->iter && i == l->iterpos)
		return l->iter->ptr;
	linkedlist_iter_calculate(l, &n, i, &dir);
	while (l->iterpos != i)
	{
		if (dir > 0)
			n = n->next;
		else if (dir < 0)
			n = n->last;
		l->iterpos += dir;
	}
	l->iter = n;
	return n->ptr;
}

int
linkedlist_search(struct linkedlist_s *l,
                  void *val,
                  size_t *i)
{
	struct node_s *n;
	size_t j;
	if (!l)
		return 0;
	n = l->head;
	j = 0;
	while (j < l->len)
	{
		if (n->ptr == val)
		{
			*i = j;
			return 1;
		}
		++j;
		n = n->next;
	}
	return 0;
}

size_t
linkedlist_size(struct linkedlist_s *l)
{
	if (!l)
		return 0;
	return l->len;
}

