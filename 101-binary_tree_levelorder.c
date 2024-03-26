#include "binary_trees.h"
#include "queue.h"

/**
 *  * binary_tree_levelorder - Performs level-order traversal of a binary tree
 *   * @tree: Pointer to the root node of the tree to traverse
 *    * @func: Pointer to a function to call for each node
 *     The value in the node must be passed as a parameter to this function
 *      *
 *       * Description: This function traverses the binary tree level by level,
 *        *              starting from the root and moving downwards.
 *        It calls the given function for each node in the tree
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;

	/* Check if tree or func is NULL */
	if (tree == NULL || func == NULL)
		return;

	/* Initialize the queue and enqueue the root node */
	queue = queue_create();
	if (queue == NULL)
		return;

	queue_push(queue, (void *)tree);

	/* Process nodes in the queue until it becomes empty */
	while (!queue_is_empty(queue))
	{
		const binary_tree_t *current = (const binary_tree_t *)queue_pop(queue);

		/* Call the given function for the current node */
		func(current->n);

		/* Enqueue the left and right children of the current node */
		if (current->left != NULL)
			queue_push(queue, (void *)current->left);
		if (current->right != NULL)
			queue_push(queue, (void *)current->right);

	}

	/* Free the queue */
	queue_destroy(queue);
}
