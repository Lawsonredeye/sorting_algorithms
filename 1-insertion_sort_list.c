#include <stdlib.h>
#include "sort.h"

/**
 * swap - used for swapping two element value together
 * @xp: pointer to an array
 * @yp: pointer to an array
 *  Return: nothing as it just swaps elements from the memory address
 *      */
void swap_nodes(listint_t **list, listint_t *prev_node, listint_t *next_node)
{
        listint_t *temp1, *temp2;

        /* if there are next to each other, then swap the address of one with the other. */
        if (prev_node->next == next_node)
        {
                prev_node->next = next_node->next;
                next_node->prev = prev_node->prev;
                next_node->next = prev_node;
                prev_node->prev = next_node;
        }

        else
        {
                /* swap their link separately */
                temp1 = prev_node->next;
                temp2 = next_node->prev;
                prev_node->next = next_node->next;
                prev_node->prev = temp1->prev;
                next_node->next = temp1;
                next_node->prev = temp1->prev;
                temp1->prev = next_node;
                temp2->next = prev_node;
        }

        if (*list == prev_node)
        {
                *list = next_node;
        }
        else if (*list == next_node)
        {
                *list = prev_node;
        }


        if (prev_node->next != NULL)
        {
                prev_node->next->prev = prev_node;
        }
        if (next_node->next != NULL)
        {
                next_node->next->prev = next_node;
        }
        if (prev_node->prev != NULL)
        {
                prev_node->prev->next = prev_node;
                prev_node->prev = temp1->prev;
                next_node->next = temp1;
                next_node->prev = temp1->prev;
                temp1->prev = next_node;
                temp2->next = prev_node;
        }

        if (*list == prev_node)
        {
                *list = next_node;
        }
        else if (*list == next_node)
        {
                *list = prev_node;
        }


        if (prev_node->next != NULL)
        {
                prev_node->next->prev = prev_node;
        }
        if (next_node->next != NULL)
        {
                next_node->next->prev = next_node;
        }
        if (prev_node->prev != NULL)
        {
                prev_node->prev->next = prev_node;
f (next_node->prev != NULL)
        {
                next_node->prev->next = next_node;
        }
}


void insertion_sort_list(listint_t **list)
{
        listint_t *sort, *not_sort, *next_node, *this_node;
        if (*list == NULL || (*list)->next == NULL)
        {
                return;
        }

        sort = *list;
        not_sort = (*list)->next;


        while (not_sort != NULL)
        {
                next_node = not_sort->next;
                this_node = sort;

                while (this_node != NULL)
                {
                        if (not_sort->n < this_node->n)
                        {
                                swap_nodes(list, this_node, not_sort);
                                print_list(*list);
                                break;
                        }
                        this_node = this_node->prev;
                }
                sort = sort->next;
                not_sort = next_node;
        }
}
