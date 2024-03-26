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

	queue_push(queue, (void *)tree);

	int non_full_node_encountered = 0;

	while (!queue_is_empty(queue))
	{
		const binary_tree_t *current = (const binary_tree_t *)queue_pop(queue);

		if (non_full_node_encountered && (current->left || current->right))
		{
			queue_destroy(queue);
			return (0);
		}

		if (current->left == NULL && current->right != NULL)
		{
			queue_destroy(queue);
			return (0);
		}

		if (current->left)
			queue_push(queue, (void *)current->left);

		if (current->right == NULL)
			non_full_node_encountered = 1;
		else
			queue_push(queue, (void *)current->right);
	}

	queue_destroy(queue);
	return (1);
}
