#include "binary_trees.h"

/**
 *  * binary_tree_sibling - Finds the sibling of a node
 *   * @node: Pointer to the node to find the sibling
 *    *
 *     * Return: Pointer to the sibling node, or NULL if node is NULL,
 *      *         the parent is NULL, or if node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if node or its parent is NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Check if node is the left child */
	if (node == node->parent->left)
		return (node->parent->right);

	/* Check if node is the right child */
	if (node == node->parent->right)
		return (node->parent->left);

	/* If node is neither left nor right child, return NULL */
	return (NULL);
}
