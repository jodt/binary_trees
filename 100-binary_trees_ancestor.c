#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node or NULL if not found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depthFirst = binary_tree_depth(first);
	size_t depthSecond = binary_tree_depth(second);

	if (!first || !second)
		return (NULL);

	same_level(depthFirst, depthSecond, &first, &second);

	if (first == second)
		return ((binary_tree_t *)first);

	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - Measures the depth of a node in binary tree.
 * @tree: pointer to the node to measure the depth
 *
 * Return: the depth of the binary tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}

/**
 * same_level - puts second and first at the same depth
 * @a: int
 * @b: int
 * @first: adress of the pointer of the node first
 * @second: adress of the pointer of the node second
 * Return: max of a or b
 */

void same_level(int a, int b, const binary_tree_t **first,
		const binary_tree_t **second)
{
	if (a == b)
		return;
	if (a > b)
	{
		while (a != b)
		{
			*first = (*first)->parent;
			a--;
		}
	}
	else
	{

		while (b != a)
		{
			*second = (*second)->parent;
			b--;
		}
	}
}
