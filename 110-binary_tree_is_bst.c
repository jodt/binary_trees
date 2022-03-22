#include "binary_trees.h"

int getMax(binary_tree_t *root);
int getMin(binary_tree_t *root);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if valid and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left)
	{
		if (getMax(tree->left) > tree->n)
			return (0);
	}

	if (tree->right)
	{
		if (getMin(tree->right) < tree->n)
			return (0);
	}

	return (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->right));
}

/**
 * getMin - Return the minimum value of a BST
 * @root: pointer of the root node
 * Return: min value of the BST
 */

int getMin(binary_tree_t *root)
{
	binary_tree_t *temp = root;

	if (root == NULL)
		return (1);

	while (temp->left)
		temp = temp->left;

	return (temp->n);
}

/**
 * getMax - Return the maximum value of a BST
 * @root: pointer of the root node
 * Return: max value of the BST
 */
int getMax(binary_tree_t *root)
{
	binary_tree_t *temp = root;

	if (root == NULL)
		return (1);

	while (temp->right)
		temp = temp->right;

	return (temp->n);
}
