#include "binary_trees.h"
bst_t *insert_node(bst_t **tree, int value, bst_t **parent);
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: eturn a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *prev, *current, *new_node;

	if (*tree)
	{
		current = *tree;
		while (current != NULL)
		{
			prev = current;
			if (value == current->n)
				return (NULL);
			else if (value < current->n)
				current = current->left;
			else
				current = current->right;
		}

		new_node = binary_tree_node(prev, value);
		if (value < prev->n)
		{
			prev->left = new_node;
			return (prev->left);
		}
		else
		{
			prev->right = new_node;
			return (prev->right);
		}
	}
	else
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
}
