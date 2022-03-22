#include "binary_trees.h"
/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: returns a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root, *temp;

	if (tree == NULL)
		return (NULL);
	if (tree->left == NULL && tree->right == NULL)
		return (tree);
	if (tree->right)
	{
		if (tree->right->left)
		{
			root = tree->right;
			temp = root->left;
			temp->parent = tree;
			tree->right = temp;
			root->left = tree;
			tree->parent = root;
			root->parent = NULL;
		}
		else
		{
			root = tree->right;
			root->parent = NULL;
			root->left = tree;
			tree->parent = root;
			tree->right = NULL;
		}
	}
	return (root);
}
