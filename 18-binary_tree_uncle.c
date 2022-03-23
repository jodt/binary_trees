#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: pointer to the uncle node or NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent;
	binary_tree_t *parent;

	if (!node)
		return (NULL);

	if (node->parent)
		parent = node->parent;
	else
		return (NULL);

	if (parent->parent)
		grandparent = parent->parent;
	else
		return (NULL);

	return (grandparent->left == parent ? grandparent->right : grandparent->left);
}
