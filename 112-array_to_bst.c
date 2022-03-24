#include "binary_trees.h"

/**
 * array_to_bst - Builds a BST from an array.
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in the array
 * Return: pointer to the root node or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i = 0;

	if (!array || !size)
		return (NULL);

	while (i < size)
	{
		bst_insert(&root, *array++);
		i++;
	}
	return (root);
}
