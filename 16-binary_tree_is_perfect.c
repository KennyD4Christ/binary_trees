#include "binary_trees.h"

/**
 *  * binary_tree_height - Measures the height of a binary tree
 *   * @tree: Pointer to the root node of the tree to measure the height
 *    *
 *     * Return: Height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 *  * binary_tree_is_perfect - Checks if a binary tree is perfect
 *   * @tree: Pointer to the root node of the tree to check
 *    *
 *     * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, expected_nodes, actual_nodes;

	if (tree == NULL)
		return (0);

	/* Calculate the height of the tree */
	height = binary_tree_height(tree);

	/* Calculate the number of nodes expected in a perfect binary tree */
	expected_nodes = (1 << height) - 1;

	/* Calculate the number of nodes in the actual tree */
	actual_nodes = binary_tree_size(tree);

	/* Check if the number of nodes matches the expected number */
	return (expected_nodes == actual_nodes);
}
