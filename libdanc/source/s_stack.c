/*
 * ________________________________________________________________________________
 * |  File: s_stack.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:59 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"


t_stack *create_stack()
{
	t_stack *new;
	new = msg_malloc(sizeof(t_stack), "Stack could not be created");
	if (!new)
		return (NULL);
	new->top = NULL;
	return (new);
}

void push(t_stack *stack, int data)
{
	int *data_ptr = msg_malloc(sizeof(int), "push() malloc failed");
	*data_ptr = data;
	insert_front(&stack->top, data_ptr);
}

int pop(t_stack *stack)
{
	if (stack->top == NULL)
	{
		save_to_error_txt("pop() called on empty stack");
		return 0;
	}
		
	int data = *(int *)stack->top->data;
	delete_front(&(stack->top));
	return data;
}

void print_stack(t_stack *stack)
{
	if (stack->top == NULL)
	{
		printf("stack is empty\n");
		return ;
	}
	print_nodes(stack->top);
}

int	stack_peek(t_stack *stack)
{
	if (stack->top == NULL)
	{
		save_to_error_txt("stack_peek() called on empty stack");
		return -2147483647;
	}
	int data = *(int *)stack->top->data;
	return data;
}

