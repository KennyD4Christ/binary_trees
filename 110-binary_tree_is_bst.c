#include "binary_trees.h"

/**
 *  * binary_tree_is_bst - Checks if a binary tree is a
 *  valid Binary Search Tree.
 *   * @tree: A pointer to the root node of the tree to check.
 *    *
 *     * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_check(tree, NULL, NULL));
}

/**
 *  * bst_check - Recursive helper function to check if a tree is a valid BST.
 *   * @tree: A pointer to the current root node.
 *    * @min: A pointer to the minimum value the node can take.
 *     * @max: A pointer to the maximum value the node can take.
 *      *
 *       * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int bst_check(const binary_tree_t *tree, const binary_tree_t *min,
	      const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if ((min != NULL && tree->n <= min->n) || (max != NULL && tree->n >= max->n))
		return (0);

	return (bst_check(tree->left, min, tree) &&
		bst_check(tree->right, tree, max));
}

