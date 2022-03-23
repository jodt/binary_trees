#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size_tree;

	if (tree)
	{
		size_tree = binary_tree_size(tree);
		return (iscomplete(tree, 0, size_tree));
	}
	return (0);
}

/**
 * iscomplete - check if binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the current node
 * @number_of_nodes: number of nobes
 *
 * Return: 1 if tree is complete else 0
 */
int iscomplete(const binary_tree_t *tree, int index, int number_of_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= number_of_nodes)
		return (0);

	return (iscomplete(tree->left, 2 * index + 1, number_of_nodes) &&
		iscomplete(tree->right, 2 * index + 2, number_of_nodes));
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
