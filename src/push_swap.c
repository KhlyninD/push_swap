/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:33:56 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/23 18:08:13 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	init_stacks(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->flag_sort = 1;
	stacks->many_pb = -1;
	stacks->el_a = NULL;
	stacks->el_b = NULL;
	stacks->a_r_rr = 1;
	stacks->a_r_rr = 1;
	stacks->size_r_rr = -1;
	stacks->is_set = 0;
}

static void	final_sort(t_stacks *stacks)
{
	t_stack_elem	*el;

	stacks->ra = 0;
	el = stacks->stack_a->head;
	while (el->index != 0)
	{
		stacks->ra++;
		el = el->next;
	}
	stacks->rra = stacks->stack_a->size - stacks->ra;
	while (stacks->stack_a->head->index != 0)
	{
		if (stacks->ra < stacks->rra)
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
}

static int	splited_size(char **words)
{
	int	size;

	size = 0;
	while (*words)
	{
		words++;
		size++;
	}
	return (size);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*str;

	init_stacks(&stacks);
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		str = ft_strjoin("!push_swap ", argv[1]);
		argv = ft_split(str, ' ');
		free(str);
		argc = splited_size(argv);
	}
	lst_init_a(argv, &stacks);
	if (argv && argv[0][0] == '!')
		free_after_split(argv);
	if ((argc - 1) != stacks.stack_a->size)
		error("bad malloc el_new", 3, &stacks, NULL);
	if (stacks.stack_a->size < 4 || stacks.flag_sort)
		unique_num(&stacks);
	min_push_b(&stacks);
	push_a(&stacks);
	final_sort(&stacks);
	free_stacks(&stacks);
	return (0);
}
