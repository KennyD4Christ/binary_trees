#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>

/**
 *  * struct binary_tree_s - Binary tree node
 *   *
 *    * @n: Integer stored in the node
 *     * @parent: Pointer to the parent node
 *      * @left: Pointer to the left child node
 *       * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
	int height;
};

typedef struct binary_tree_s binary_tree_t;

/* Binary Search Tree */
typedef struct binary_tree_s bst_t;

/* AVL Tree */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int bst_check(const binary_tree_t *tree, const binary_tree_t *min,
	      const binary_tree_t *max);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
			    avl_t **new, int value);
avl_t *array_to_avl(int *array, size_t size);
void bal(avl_t **tree);
int successor(bst_t *node);
int remove_type(bst_t *root);
bst_t *bst_remove(bst_t *root, int value);
avl_t *avl_remove(avl_t *root, int value);
void create_tree(avl_t **node, int *array, size_t size, int mode);
avl_t *sorted_array_to_avl(int *array, size_t size);
int check_max(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
size_t binary_tree_size(const binary_tree_t *tree);
heap_t *array_to_heap(int *array, size_t size);
size_t tree_height(const heap_t *tree);
size_t tree_size_h(const binary_tree_t *tree);
void _preorder(heap_t *tree, heap_t **node, size_t height);
void heapify(heap_t *root);
int heap_extract(heap_t **root);
size_t tree_size(const binary_tree_t *tree);
int *heap_to_sorted_array(heap_t *heap, size_t *size);

/* Macro to return the maximum of two values */
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#endif /* BINARY_TREES_H */