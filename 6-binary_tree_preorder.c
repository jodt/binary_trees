#include "binary_trees.h"

/**
 * binary_tree_preorder - Prints a binary tree using preorder traversal
 * @tree: pointer to the root node
 * @func: pointer to function to call for each node
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n); /* print value of the node */
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
