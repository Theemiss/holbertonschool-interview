#include "lists.h"
/**
 * check_cycle - check if linked list has cycle
 * @list: single linked list
 * Return:0 or  1
 */
int check_cycle(listint_t *list)
{
	void *array[1024];
	listint_t *temp;
	int i = 0;
	int z = 0;

	temp = list;
	while (temp)
	{
		temp = temp->next;
		array[i] = &temp;
		i++;
		for (z = 0; z < i; z++)
		{
			if (&temp == array[i])
			{
				return (1);
			}
		}
	}
	return (0);
}
