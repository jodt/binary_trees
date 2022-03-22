#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: the node or NULL if node is NULL or parent is NULL
 * if node has no sibling return NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = node;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;

	return (node == parent->left ? parent->right : parent->left);
}
