#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a BST
 * @tree: pointer to the root node of the BST
 * @value: value to search in the tree
 * Return: pointer to the containing the value or NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (tree)
	{
		if (value == tree->n)
			return ((bst_t *)tree);

		if (value < tree->n)
			tree = tree->left;

		else
			tree = tree->right;
	}
	return (NULL);
}
