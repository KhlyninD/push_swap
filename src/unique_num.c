/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:46:47 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/18 15:55:35 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	unique_num2(t_stack *stack_a)
{
	if (stack_a->head->value != stack_a->head_index->value)
		ft_putstr_fd("sa\n", 1);
}

static void	unique_num3(t_stack *stack_a)
{
	if (stack_a->head->value > stack_a->head->next->value
		|| stack_a->head->next->value > stack_a->head->prev->value)
	{
		if (stack_a->head->value > stack_a->head->next->value)
		{
			if (stack_a->head->value < stack_a->head->prev->value)
				ft_putstr_fd("sa\n", 1);
			else if (stack_a->head->next->value < stack_a->head->prev->value)
				ft_putstr_fd("ra\n", 1);
			else
				ft_putstr_fd("sa\nrra\n", 1);
		}
		else if (stack_a->head->value > stack_a->head->prev->value)
			ft_putstr_fd("rra\n", 1);
		else
			ft_putstr_fd("sa\nra\n", 1);
	}
}

void	unique_num(t_stacks *stacks)
{
	if (!stacks->flag_sort && stacks->stack_a->size != 1)
	{
		if (stacks->stack_a->size == 2)
			unique_num2(stacks->stack_a);
		else if (stacks->stack_a->size == 3)
			unique_num3(stacks->stack_a);
	}
	free_stacks(stacks);
	exit(0);
}
