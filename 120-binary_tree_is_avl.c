#include "binary_trees.h"

/**
 *  * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 *   * @tree: A pointer to the root node of the tree to check.
 *    * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);


	int left_height = binary_tree_height(tree->left);
	int right_height = binary_tree_height(tree->right);


	int balance = abs(left_height - right_height);


	if (balance > 1 || (!binary_tree_is_avl(tree->left) && balance > 0) ||
	    (!binary_tree_is_avl(tree->right) && balance > 0))

		return (0);

	return (1);
}
