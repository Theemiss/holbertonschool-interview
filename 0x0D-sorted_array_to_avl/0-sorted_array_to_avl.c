#include "binary_trees.h"
/**
 * ArrayToBST - recursive function to change sorted array to BST.
 *
 * @array: array to convert.
 * @start: start
 * @end: end idx
 * @par: parent node
 *
 * Return:root of BST created.
 */
avl_t *ArrayToBST(int *array, int start, int end, avl_t *par)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;

	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);
	root->n = array[mid];
	root->parent = par;
	root->left = ArrayToBST(array, start, mid - 1, root);
	root->right = ArrayToBST(array, mid + 1, end, root);
	return (root);
}
/**
 * sorted_array_to_avl - convert a sorted array to an AVL
 *
 * @array: array to convert.
 * @size: size of the array.
 *
 * Return: root node of the created AVL tree, NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);

	return (ArrayToBST(array, 0, size - 1, NULL));
}
