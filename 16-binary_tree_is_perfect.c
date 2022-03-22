#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (binary_tree_balance(tree) == 0)
	{
		return (binary_tree_is_full(tree));
	}
	return (0);
}

/**
 * binary_tree_balance - Balance factor of a binary tree.
 * @tree: point to root node of the tree
 *
 * Return: the balance factor of a binary tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
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
 * binary_tree_is_full - checks if a binary tree is full
 *@tree: pointer to the root node of the tree to check
 *
 * Return: 1 is tree is full else 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	else if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) * binary_tree_is_full(tree->right));
	else
		return (0);
}
