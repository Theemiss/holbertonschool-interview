#include "binary_trees.h"
/**
*
*
*
*/
int heap_extract(heap_t **root)
{
    int value;
    if(!*root)
        return (0);
    value = (*root)->n;
    if (!(*root)->left)
	{
		value = (*root)->n;
		free(*root);
		*root = NULL;
		return (value);
	}
    extract(*root);
    return (value);

}
void extract(heap_t *tree)
{
	heap_t *sub_max, *right_max = NULL;

	if (!tree->left)
		return;
	sub_max = find_max((tree)->left);
	if (tree->right)
		right_max = find_max(tree->right);
	if (right_max && right_max->n > sub_max->n)
		sub_max = right_max;
	tree->n = sub_max->n;
	if (!sub_max->left)
	{
		if (sub_max->parent && sub_max->parent->left == sub_max)
			sub_max->parent->left = NULL;
		if (sub_max->parent && sub_max->parent->right == sub_max)
			sub_max->parent->right = NULL;
		free(sub_max);
	}
	else
		extract(sub_max);
}
heap_t *find_max(heap_t *tree)
{
    heap_t *curr_max, *left_max, *right_max;

	if (!tree->left)
		return (tree);
	left_max = find_max(tree->left);
	if (left_max->n > tree->n)
		curr_max = left_max;
	else
		curr_max = tree;
	if (tree->right)
	{
		right_max = find_max(tree->right);
		if (right_max->n > curr_max->n)
			curr_max = right_max;
		else
			curr_max = tree;
	}
	return (curr_max);
}