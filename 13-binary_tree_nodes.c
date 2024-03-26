#include "binary_trees.h"

/**
 *  * binary_tree_nodes - Counts the nodes with at least 1 child
 *  in a binary tree
 *   * @tree: Pointer to the root node of the tree to count the nodes
 *    *
 *     * Return: Number of nodes with at least 1 child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if the node has at least 1 child */
	if (tree->left != NULL || tree->right != NULL)
	{
		/*
		 * Recursively count the nodes in the left and right subtrees
		 */
		size_t left_nodes = binary_tree_nodes(tree->left);
		size_t right_nodes = binary_tree_nodes(tree->right);

		/*
		 * Return the sum of nodes in the left and right subtrees
		 * plus 1 for the current node
		 */
		return (left_nodes + right_nodes + 1);
	}

	/* If the node has no children, return 0 */
	return (0);
}
