/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:35:43 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/18 15:53:18 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rb_rrb(t_stacks *stacks)
{
	if (stacks->b_r_rr == 1)
	{
		stacks->stack_b->head = stacks->stack_b->head->next;
		ft_putstr_fd("rb\n", 1);
	}
	else
	{
		stacks->stack_b->head = stacks->stack_b->head->prev;
		ft_putstr_fd("rrb\n", 1);
	}
}

static void	ra_rra(t_stacks *stacks)
{
	if (stacks->a_r_rr == 1)
	{
		stacks->stack_a->head = stacks->stack_a->head->next;
		ft_putstr_fd("ra\n", 1);
	}
	else
	{
		stacks->stack_a->head = stacks->stack_a->head->prev;
		ft_putstr_fd("rra\n", 1);
	}
}

static void	rr_rrr(t_stacks *stacks)
{
	if (stacks->a_r_rr == 1)
	{
		stacks->stack_a->head = stacks->stack_a->head->next;
		stacks->stack_b->head = stacks->stack_b->head->next;
		ft_putstr_fd("rr\n", 1);
	}
	else
	{
		stacks->stack_a->head = stacks->stack_a->head->prev;
		stacks->stack_b->head = stacks->stack_b->head->prev;
		ft_putstr_fd("rrr\n", 1);
	}
}

void	rx_rrx(t_stacks *stacks)
{
	while (stacks->el_a != stacks->stack_a->head
		|| stacks->el_b != stacks->stack_b->head)
	{
		if (stacks->a_r_rr == stacks->b_r_rr
			&& stacks->el_a != stacks->stack_a->head
			&& stacks->el_b != stacks->stack_b->head)
			rr_rrr(stacks);
		else if (stacks->el_a != stacks->stack_a->head)
			ra_rra(stacks);
		else if (stacks->el_b != stacks->stack_b->head)
			rb_rrb(stacks);
	}
}
