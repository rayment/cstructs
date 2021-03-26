/*
 * linkedlist.h
 * Linked list header.
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 15/03/2021
 */

#ifndef _RAYMENT_FR_CSTRUCTS_LINKEDLIST_H
#define _RAYMENT_FR_CSTRUCTS_LINKEDLIST_H 1

#include <stdlib.h>

struct
node_s
{
	void *ptr;
	struct node_s *next;
	struct node_s *last;
};

struct
linkedlist_s
{
	struct node_s *head, *tail, *iter;
	size_t len, iterpos;
};

#define linkedlist_iter_s node_s

/* List functions. */

/*
 * Create a new linked list pointer containing 0 elements.
 */
struct linkedlist_s *linkedlist_init();
/*
 * Free a linked list from memory.
 */
void                 linkedlist_free(struct linkedlist_s *);
/*
 * Add an element to the end of a linked list.
 * If an error occurred, NULL is returned.
 */
void                *linkedlist_add(struct linkedlist_s *, void *);
/*
 * Remove an element at a certain index from a linked list and return it.
 * If an error occurred, NULL is returned.
 */
void                *linkedlist_remove(struct linkedlist_s *, size_t);
/*
 * Remove all elements from a linked list. Does nothing if it is empty.
 */
void                 linkedlist_clear(struct linkedlist_s *);
/*
 * Get an element at a certain index from a linked list and return it.
 * If an error occurred, NULL is returned.
 */
void                *linkedlist_get(struct linkedlist_s *, size_t);
/*
 * Search a linked list for an element and store the index it is found in.
 * If the element is found, 1 is returned, otherwise 0.
 * If an error occurred, 0 is returned.
 */
int                  linkedlist_search(struct linkedlist_s *, void *, size_t *);
/*
 * Get the size of a linked list, or return 0 in case of error.
 */
size_t               linkedlist_size(struct linkedlist_s *);

/* Iterator functions. */

/*
 * Get an iterator for a linked list pointing to the beginning of the list.
 */
struct linkedlist_iter_s *linkedlist_iter_begin(struct linkedlist_s *);
/*
 * Get an iterator for a linked list pointing to the end of the list.
 */
struct linkedlist_iter_s *linkedlist_iter_end(struct linkedlist_s *);
/*
 * Return the current iterator value and advance to the next element.
 */
void                     *linkedlist_iter_next(struct linkedlist_iter_s **);
/*
 * Return the current iterator value and advance to the previous element.
 */
void                     *linkedlist_iter_prev(struct linkedlist_iter_s **);
/*
 * Return 1 if an iterator has more elements in front of it,
 * or 0 if not or in case of error.
 */
int                       linkedlist_iter_hasnext(struct linkedlist_iter_s *);
/*
 * Return 1 if an iterator has more elements behind it,
 * or 0 if not or in case of error.
 */
int                       linkedlist_iter_hasprev(struct linkedlist_iter_s *);

#endif /* _RAYMENT_FR_CSTRUCTS_LINKEDLIST_H */

