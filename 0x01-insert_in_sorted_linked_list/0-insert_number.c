#include "lists.h"
#include <stdlib.h>

/**
* insert_node - insert a node in sorted linked list
 * @head: head of the list
 * @number: the number to insert
 * Return: new head
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *node;
	node = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if (*head == NULL || (*head)->n >= new->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (node = *head; node != NULL; node = node->next)
	{
		if (node->next == NULL || node->next->n > new->n)
		{

			new->next = node->next;
			node->next = new;
			break;
		}
	}
	return (new);
}