#include "binary_trees.h"

/**
 *  * binary_tree_depth - Measures the depth of a node in a binary tree
 *   * @tree: Pointer to the node to measure the depth
 *    *
 *     * Return: Depth of the node, or 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}

/**
 *  * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *   * @first: Pointer to the first node
 *    * @second: Pointer to the second node
 *     *
 *      * Return: Pointer to the lowest common ancestor node,
 *       *         or NULL if no common ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	/* Calculate the depths of the two nodes */
	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	/* Move the deeper node up to the same depth as the shallower node */
	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}


	/* Move both nodes up simultaneously until the LCA is found */
	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}


	/* Return the LCA */
	return ((binary_tree_t *)first);
}
