#include "binary_trees.h"
#include "queue.h"

/**
 *  * binary_tree_is_complete - Checks if a binary tree is complete
 *   * @tree: Pointer to the root node of the tree to check
 *    *
 *     * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Create a queue for level-order traversal */
	queue_t *queue = queue_create();
	if (queue == NULL)
		return (0);

	/* Enqueue the root node */
	queue_push(queue, (void *)tree);

	/* Flag to mark if a non-full node is encountered */
	int non_full_node_encountered = 0;

	/* Perform level-order traversal */
	while (!queue_is_empty(queue))
	{
		const binary_tree_t *current = (const binary_tree_t *)queue_pop(queue);

		/* If a non-full node is found after a full node, tree is not complete */
		if (non_full_node_encountered && (current->left || current->right))
		{
			queue_destroy(queue);
			return (0);
		}

		/* If the left child is NULL and the right child is not NULL, tree is not complete */
		if (current->left == NULL && current->right != NULL)
		{
			queue_destroy(queue);
			return (0);
		}

		/* If the left child is not NULL, enqueue it */
		if (current->left)
			queue_push(queue, (void *)current->left);

		/* If the right child is NULL, mark that a non-full node is encountered */
		if (current->right == NULL)
			non_full_node_encountered = 1;

		/* If the right child is not NULL, enqueue it */
		else
			queue_push(queue, (void *)current->right);
	}


	/* Tree is complete */
	queue_destroy(queue);
	return (1);
}
