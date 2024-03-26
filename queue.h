#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "binary_trees.h"

/* Structure for a queue node */
typedef struct queue_node {
	struct queue_node *next;
	const binary_tree_t *tree_node;
} queue_node_t;

/* Structure for a queue */
typedef struct queue {
	queue_node_t *front;
	queue_node_t *rear;
} queue_t;

/* Function prototypes */
queue_t *queue_create(void);
void queue_push(queue_t *queue, const binary_tree_t *tree_node);
const binary_tree_t *queue_pop(queue_t *queue);
int queue_is_empty(const queue_t *queue);
void queue_destroy(queue_t *queue);

#endif /* QUEUE_H */
