#include "lists.h"
/**
* find_listint_loop - find the loop in single linked list
* @head: the head of the single linked list
* Return: the node which the loop occured
*/

listint_t *find_listint_loop(listint_t *head)
{
listint_t *first, *second;

	first = head;
	second = head;
	while (head)
	{
		while (second && second->next)
		{
			second = second->next->next;
			first = first->next;
			if (second == first)
			{
				while (first)
				{
					first = first->next;
					if (first == head)
						return (first);
					else if (second == first)
					{
						head = head->next;
						break;
					}
				}
			}
		}
		head = head->next;
	}
	return (NULL);
}
