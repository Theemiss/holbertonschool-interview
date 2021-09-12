#include "lists.h"
/**
 * check_cycle - check if linked list has cycle
 * @list: single linked list
 * Return:0 or  1
 */
int check_cycle(listint_t *list)
{

	listint_t *temp, *check;

	if (!list)
		return (0);

	temp = list;
	check = list->next;
	while (temp && check && check->next)
	{
		temp = temp->next;
		check = check->next->next;

		if (check == temp)
			return (1);
	}
	return (0);
}

