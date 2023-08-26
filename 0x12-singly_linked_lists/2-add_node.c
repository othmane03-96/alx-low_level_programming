#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - inserts a fresh node at the start of a linked list
 *@head: a pointer to the pointer of the list_t list
 *@str: the new string to be added into the node
 *
 * Return: the address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;

	while (str[len])
		len++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->len = len;
	new->next = (*head);
	(*head) = new;

	return (*head);
}
