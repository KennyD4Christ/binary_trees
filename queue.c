#include "queue.h"
#include "binary_trees.h"

/*
 *  * queue_create - Creates a new queue and initializes it.
 *   *
 *    * Return: Pointer to the newly created queue,
 *    or NULL if memory allocation fails.
 */
queue_t *queue_create(void)
{
	queue_t *queue = malloc(sizeof(queue_t));
	if (queue == NULL) {
		return NULL; /* Memory allocation failed */
	}

	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

/*
 *  * queue_push - Inserts a binary tree node into the queue.
 *   * @queue: Pointer to the queue.
 *    * @tree_node: Pointer to the binary tree node to be inserted.
 *     *
 *      * Return: void
 */

void queue_push(queue_t *queue, const binary_tree_t *tree_node)
{
	if (queue == NULL || tree_node == NULL) {
		return; /* Invalid queue or tree node */
	}

	queue_node_t *new_node = malloc(sizeof(queue_node_t));
	if (new_node == NULL) {
		return; /* Memory allocation failed */
	}

	new_node->tree_node = tree_node;
	new_node->next = NULL;

	if (queue->rear == NULL) {

		queue->front = new_node;
		queue->rear = new_node;
	} else {
		/* Otherwise, add the new node to the rear of the queue */
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
}
/*
 *  * queue_pop - Removes and returns the binary tree node from the queue.
 *   * @queue: Pointer to the queue.
 *    *
 *     * Return: Pointer to the binary tree node removed from the queue,
 *     or NULL if the queue is empty.
 */
const binary_tree_t *queue_pop(queue_t *queue)
{
	if (queue == NULL || queue->front == NULL) {
		return NULL; /* Invalid queue or empty queue */
	}

	/* Retrieve the binary tree node from the front of the queue */
	const binary_tree_t *tree_node = queue->front->tree_node;

	/* Remove the front node from the queue */
	queue_node_t *temp = queue->front;
	queue->front = queue->front->next;
	free(temp);

	/* Update the rear pointer if the queue becomes empty */
	if (queue->front == NULL) {
		queue->rear = NULL;
	}

	return tree_node;
}

/*
 *  * queue_is_empty - Checks if the queue is empty.
 *   * @queue: Pointer to the queue.
 *    *
 *     * Return: 1 if the queue is empty, 0 otherwise.
 */
int queue_is_empty(const queue_t *queue)
{
	return (queue == NULL || queue->front == NULL);
}

/*
 *  * queue_destroy - Destroys the queue and frees allocated memory.
 *   * @queue: Pointer to the queue.
 *    *
 *     * Return: void
 */
void queue_destroy(queue_t *queue)
{
	if (queue == NULL) {
		return; /* Invalid queue */
	}

	/* Free memory for each node in the queue */
	while (queue->front != NULL) {
		queue_node_t *temp = queue->front;
		queue->front = queue->front->next;
		free(temp);
	}

	/* Free memory for the queue structure */
	free(queue);
}
