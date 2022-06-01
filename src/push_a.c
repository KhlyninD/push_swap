/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:35:34 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/18 17:16:10 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_stack_elem	*search_pa(t_stack *a_stack, int value)
{
	t_stack_elem	*el;

	el = a_stack->head;
	if (value < el->value)
	{
		while (value < el->prev->value
			&& el->value > el->prev->value)
			el = el->prev;
	}
	else
	{
		while (value > el->value
			&& el->value < el->next->value)
			el = el->next;
		if (value > el->value && el->value > el->next->value)
			el = el->next;
	}
	return (el);
}

static void	search_rx_rrx(t_stack *stack, int value,
						size_t *rx, size_t *rrx)
{
	t_stack_elem	*el;

	el = stack->head;
	while (el->value != value)
	{
		(*rx)++;
		el = el->next;
	}
	el = stack->head;
	while (el->value != value)
	{
		(*rrx)++;
		el = el->prev;
	}
}

static void	min_pa(size_t size, t_stacks new_stacks, t_stacks *stacks)
{
	if (!stacks->is_set || size < stacks->size_r_rr)
	{
		stacks->el_a = new_stacks.el_a;
		stacks->el_b = new_stacks.el_b;
		stacks->a_r_rr = new_stacks.a_r_rr;
		stacks->b_r_rr = new_stacks.b_r_rr;
		stacks->size_r_rr = size;
		stacks->is_set = 1;
	}
}

static void	optimal_push_a(t_stacks *stacks, t_stack_elem *el_b,
	t_stacks new_stacks)
{
	new_stacks.el_a = search_pa(stacks->stack_a, el_b->value);
	new_stacks.el_b = el_b;
	search_rx_rrx(stacks->stack_a, new_stacks.el_a->value,
		&new_stacks.ra, &new_stacks.rra);
	search_rx_rrx(stacks->stack_b, new_stacks.el_b->value,
		&new_stacks.rb, &new_stacks.rrb);
	new_stacks.a_r_rr = 1;
	new_stacks.b_r_rr = 1;
	if (new_stacks.ra > new_stacks.rb)
		min_pa(new_stacks.ra, new_stacks, stacks);
	else
		min_pa(new_stacks.rb, new_stacks, stacks);
	new_stacks.a_r_rr = 2;
	min_pa(new_stacks.rra + new_stacks.rb, new_stacks, stacks);
	new_stacks.b_r_rr = 2;
	if (new_stacks.rra > new_stacks.rrb)
		min_pa(new_stacks.rra, new_stacks, stacks);
	else
		min_pa(new_stacks.rrb, new_stacks, stacks);
	new_stacks.a_r_rr = 1;
	min_pa(new_stacks.ra + new_stacks.rrb, new_stacks, stacks);
}

void	push_a(t_stacks *stacks)
{
	size_t			i;
	t_stack_elem	*el;
	t_stacks		new_stacks;

	while (stacks->stack_b->size)
	{
		i = 0;
		stacks->is_set = 0;
		el = stacks->stack_b->head;
		while (i < stacks->stack_b->size)
		{
			new_stacks.ra = 0;
			new_stacks.rra = 0;
			new_stacks.rb = 0;
			new_stacks.rrb = 0;
			optimal_push_a(stacks, el, new_stacks);
			i++;
			el = el->next;
		}
		rx_rrx(stacks);
		px(stacks->stack_b, stacks->stack_a);
		ft_putstr_fd("pa\n", 1);
	}
}
