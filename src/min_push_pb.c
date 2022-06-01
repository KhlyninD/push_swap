/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_push_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:31:12 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/23 18:09:24 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static size_t	many_true_pb(t_stack_elem *el)
{
	size_t			index;
	size_t			many_pb;
	t_stack_elem	*head_pb;

	many_pb = 0;
	index = el->index;
	el->push_b = 0;
	head_pb = el->next;
	while (head_pb != el)
	{
		if (head_pb->index > index)
		{
			index = head_pb->index;
			head_pb->push_b = 0;
		}
		else
		{
			many_pb++;
			head_pb->push_b = 1;
		}
		head_pb = head_pb->next;
	}
	return (many_pb);
}

static void	search_min_pb(t_stacks *stacks)
{
	size_t			i;
	size_t			many_pb;
	t_stack_elem	*head_pb;

	i = 0;
	stacks->many_pb = stacks->stack_a->size;
	head_pb = stacks->stack_a->head;
	while (i < stacks->stack_a->size)
	{
		many_pb = many_true_pb(head_pb);
		if (many_pb < stacks->many_pb)
		{
			stacks->stack_a->head_pb = head_pb;
			stacks->many_pb = many_pb;
		}
		else if (many_pb == stacks->many_pb
			&& (!stacks->stack_a->head_pb
				|| head_pb->value < stacks->stack_a->head_pb->value))
			stacks->stack_a->head_pb = head_pb;
		i++;
		head_pb = head_pb->next;
	}
	many_true_pb(stacks->stack_a->head_pb);
}

static int	push_b(t_stack *stack_a)
{
	size_t			i;
	t_stack_elem	*el;

	i = 0;
	el = stack_a->head;
	while (i < stack_a->size)
	{
		if (el->push_b == 1)
			return (el->push_b);
		i++;
		el = el->next;
	}
	return (el->push_b);
}

static int	swap_a(t_stacks *stacks)
{
	size_t	many_pb;

	if (stacks->stack_a->size >= 2)
	{
		swap(stacks->stack_a);
		many_pb = many_true_pb(stacks->stack_a->head_pb);
		swap(stacks->stack_a);
		stacks->many_pb = many_true_pb(stacks->stack_a->head_pb);
		if (many_pb < stacks->many_pb)
			return (1);
	}
	return (0);
}

void	min_push_b(t_stacks *stacks)
{
	stacks->stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stacks->stack_b)
		error("bad malloc stack_b", 3, stacks, NULL);
	search_min_pb(stacks);
	while (push_b(stacks->stack_a))
	{
		if (swap_a(stacks))
		{
			swap(stacks->stack_a);
			ft_putstr_fd("sa\n", 1);
			stacks->many_pb = many_true_pb(stacks->stack_a->head_pb);
		}
		else if (stacks->stack_a->head->push_b)
		{
			px(stacks->stack_a, stacks->stack_b);
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			stacks->stack_a->head = stacks->stack_a->head->next;
			ft_putstr_fd("ra\n", 1);
		}
	}
}
