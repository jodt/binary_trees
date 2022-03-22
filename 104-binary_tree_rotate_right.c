#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root, *temp;

	if (tree == NULL)
		return (NULL);
	if (tree->left == NULL && tree->right == NULL)
		return (tree);
	if (tree->left)
	{
		if (tree->left->right)
		{
			root = tree->left;
			temp = root->right;
			temp->parent = tree;
			tree->left = temp;
			root->right = tree;
			tree->parent = root;
			root->parent = NULL;
		}
		else
		{
			root = tree->left;
			root->parent = NULL;
			root->right = tree;
			tree->parent = root;
			tree->left = NULL;
		}
	}
	return (root);
}
