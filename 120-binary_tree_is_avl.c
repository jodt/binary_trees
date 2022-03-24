#include "binary_trees.h"
#include <limits.h>

int is_bst_helper(const binary_tree_t *tree, int low, int high);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree.
 * @tree: pointer to the root node of the tree.
 * Return: 0 if not valid otherwise 1
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	return (binary_tree_avlrecursion((binary_tree_t *)tree));
}

/**
 * binary_tree_avlrecursion - Check the balance for every node of a binary tree
 * @tree: pointer to the root node of the binary tree
 * Return: 1 if the tree is AVL valid otherwise 0
 */

int binary_tree_avlrecursion(binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (binary_tree_balance(tree) < -1 || binary_tree_balance(tree) > 1)
		return (0);

	return (binary_tree_avlrecursion(tree->left) &&
		binary_tree_avlrecursion(tree->right));
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

	if (tree->left == NULL && tree->right == NULL)
		return (1);

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
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @high: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (is_bst_helper(tree->left, low, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}
