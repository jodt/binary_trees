#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int heigth_tree, i;

	if (tree == NULL || func == NULL)
		return;
	heigth_tree = binary_tree_height(tree);
	for (i = 1; i <= heigth_tree + 1; i++)
	{
		currentLevel(tree, func, i);
	}
}

void currentLevel(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree)
	{
		if (level == 1)
			func(tree->n);
		if (level > 1)
		{
			currentLevel(tree->left, func, level - 1);
			currentLevel(tree->right, func, level - 1);
		}
	}
}

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

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if (tree->left)
		leftHeight = binary_tree_height(tree->left) + 1;
	else
		leftHeight = 1;

	if (tree->right)
		rightHeight = binary_tree_height(tree->right) + 1;
	else
		rightHeight = 1;

	return (leftHeight > rightHeight ? leftHeight : rightHeight);
}
