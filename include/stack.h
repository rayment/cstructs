/*
 * stack.h
 * Stack header.
 *
 * Author       : Finn Rayment <finn@rayment.fr>
 * Date created : 25/03/2021
 */

#ifndef _RAYMENT_FR_CSTRUCTS_STACK_H
#define _RAYMENT_FR_CSTRUCTS_STACK_H 1

#include <stdlib.h>

#include "linkedlist.h"

/* typedef to a linked list */
#define stack_s linkedlist_s

/*
 * Create a new stack pointer containing 0 elements.
 */
struct stack_s *stack_init();
/*
 * Free a stack from memory.
 */
void            stack_free(struct stack_s *);
/*
 * Add an element to the top of a stack.
 * If an error occurred, NULL is returned.
 */
void           *stack_push(struct stack_s *, void *);
/*
 * Remove an element from the top of a stack.
 * If the stack is empty or an error occurred, NULL is returned.
 */
void           *stack_pop(struct stack_s *);
/*
 * Remove all elements from a stack. Does nothing if it is empty.
 */
void            stack_clear(struct stack_s *);
/*
 * Get the element on the top of the stack without removing it.
 * If the stack is empty or an error occurred, NULL is returned.
 */
void           *stack_peek(struct stack_s *);
/*
 * Search a stack for an element and store the index it is found in.
 * If the element is found, 1 is returned, otherwise 0.
 * If an error occurred, 0 is returned.
 */
int             stack_search(struct stack_s *, void *, size_t *);
/*
 * Get the size of a stack, or return 0 in case of error.
 */
size_t          stack_size(struct stack_s *);
/*
 * Return 1 if a stack is empty or in case of error, or 0 if not.
 */
int             stack_empty(struct stack_s *);

#endif /* _RAYMENT_FR_CSTRUCTS_STACK_H */

