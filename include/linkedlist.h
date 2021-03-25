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
	struct node_s *head, *tail;
	size_t len;
};

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
 * If an error occured, NULL is returned.
 */
void                *linkedlist_add(struct linkedlist_s *, void *);
/*
 * Remove an element at a certain index from a linked list and return it.
 * If an error occured, NULL is returned.
 */
void                *linkedlist_remove(struct linkedlist_s *, size_t);
/*
 * Get an element at a certain index from a linked list and return it.
 * If an error occured, NULL is returned.
 */
void                *linkedlist_get(struct linkedlist_s *, size_t);
/*
 * Search a linked list for an element and store the index it is found in.
 * If the element is found, 1 is returned, otherwise 0.
 * If an error occured, 0 is returned.
 */
int                  linkedlist_search(struct linkedlist_s *, void *, size_t *);
/*
 * Get the size of a linked list, or return 0 in case of error.
 */
size_t               linkedlist_size(struct linkedlist_s *);

#endif /* _RAYMENT_FR_CSTRUCTS_LINKEDLIST_H */

