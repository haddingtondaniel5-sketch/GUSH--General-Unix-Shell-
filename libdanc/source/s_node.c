/*
 * ________________________________________________________________________________
 * |  File: s_node.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:14 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

t_node 	*create_node(void *data)
{
	t_node *new;
	new = msg_malloc(sizeof(t_node), "new t_node");
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void		insert_front(t_node **head, void *data)
{
	t_node *new = create_node(data);
	new->next = *head;
	*head = new;
}

void		delete_front(t_node **head)
{
	if (*head == NULL)
		return ;
	
	t_node *temp = *head;
	*head = (*head)->next;
	free(temp);
}
void		print_nodes(t_node *head)
{
	while (head != NULL)
	{
		printf("%d\n", *(int *)(head->data));
		head = head->next;
	}
}

void		free_nodes(t_node *head)
{
	while (head != NULL)
	{
		if (head->data)
			free(head->data);
		t_node *temp = head;
		head = head->next;
		free(temp);
	}
}