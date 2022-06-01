/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:34:34 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/21 11:15:23 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

t_stack_elem	*el_new(int content)
{
	t_stack_elem	*el;

	el = (t_stack_elem *)malloc(sizeof(t_stack_elem));
	if (!el)
		return (NULL);
	el->value = content;
	el->index = 0;
	el->push_b = 0;
	el->prev = NULL;
	el->next = NULL;
	return (el);
}

void	lstadd_back(t_stack *stack, t_stack_elem *elem)
{
	t_stack_elem	*el;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->prev = stack->head;
			stack->head->next = stack->head;
		}
		else
		{
			el = stack->head->prev;
			elem->prev = el;
			el->next = elem;
			elem->next = stack->head;
			stack->head->prev = elem;
		}
		stack->size++;
	}
}

void	lstadd_front(t_stack *stack, t_stack_elem *elem)
{
	lstadd_back(stack, elem);
	stack->head = elem;
}

void	px(t_stack *stack_from, t_stack *stack_to)
{
	t_stack_elem	*el;

	stack_from->head->prev->next = stack_from->head->next;
	stack_from->head->next->prev = stack_from->head->prev;
	stack_from->size--;
	el = stack_from->head;
	stack_from->head = stack_from->head->next;
	el->next = NULL;
	el->prev = NULL;
	el->push_b = 0;
	lstadd_front(stack_to, el);
}

void	swap(t_stack *stack)
{
	t_stack_elem	*el;

	el = stack->head;
	stack->head->prev->next = stack->head->next;
	stack->head->next->prev = stack->head->prev;
	stack->head = stack->head->next;
	el->next = stack->head->next;
	stack->head->next->prev = el;
	el->prev = stack->head;
	stack->head->next = el;
}
