#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if tree is NULL, otherwise height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftHeight = 0;
	size_t rightHeight = 0;

	if (tree == NULL) /* if node doesnt exist */
		return (0);

	if (tree->left == NULL && tree->right == NULL) /* if its a leaf node */
		return (0);

	leftHeight = binary_tree_height(tree->left);
	rightHeight = binary_tree_height(tree->right);

	/* printf("left: %li right: %li\n", leftHeight, rightHeight); */

	return (leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1);
}
