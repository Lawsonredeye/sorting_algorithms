#include "sort.h"
#include <stddef.h>
/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swapped(listint_t *node, listint_t **list)
{
	listint_t *prev_node = node->prev, *current_node = node;
	/* first, the next of the prev_node points to the next of the current node  */

	prev_node->next = current_node->next;
	if (current_node->next != NULL) 
		/* checks if it is not at the last node, if it is not, it keeps on traversing the list */
		current_node->next->prev = prev_node;
	current_node->next = prev_node;
	current_node->prev = prev_node->prev;
	prev_node->prev = current_node;
	if (current_node->prev)
		current_node->prev->next = current_node;
	else
		*list = current_node;
	return (current_node);
}


/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swapped(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
