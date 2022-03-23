#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int heigth = binary_tree_height(tree);
	int size = binary_tree_size(tree);

	if (((_pow_recursion(2, heigth)) - 1) == size)
		return (1);
	return (0);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: number of node or 0 if tree is null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
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

/**
 * _pow_recursion - return the value of x raised to the power of y.
 * @x: Integer
 * @y: Integer
 *
 * Return: return x^y
 */

int _pow_recursion(int x, int y)
{
	if (x == 1 || y == 0)
		return (1);

	if (y < 0)
		return (-1);

	return (x * _pow_recursion(x, y - 1));
}
