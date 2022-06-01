/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:42:18 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/18 17:06:10 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	check_arg(char *str, t_stacks *stacks, char **argv)
{
	size_t			i;
	int				p;
	unsigned long	result;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	p = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			p = -1;
	if (!str[i])
		error("Argument char!", 2, stacks, argv);
	result = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error("Argument char or/and double!", 2, stacks, argv);
		if (result * 10 + (str[i] - '0') > 2147483648 && p == -1)
			error("Numb < INT_MIN!", 2, stacks, argv);
		else if (result * 10 + (str[i] - '0') > 2147483647 && p == 1)
			error("Numb > INT_MAX!", 2, stacks, argv);
		result = result * 10 + (str[i] - '0');
		i++;
	}
}

void	lst_init_a(char **argv, t_stacks *stacks)
{
	size_t	i;
	size_t	j;

	stacks->stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stacks->stack_a)
		error("bad malloc stack_a", 3, stacks, argv);
	i = 0;
	while (argv[++i])
	{
		check_arg(argv[i], stacks, argv);
		lstadd_back(stacks->stack_a, el_new(ft_atoi(argv[i])));
		j = 0;
		while (argv[++j])
		{
			if (stacks->stack_a->head->prev->value > ft_atoi(argv[j]))
				stacks->stack_a->head->prev->index++;
			if (j > i && stacks->stack_a->head->prev->value == ft_atoi(argv[j]))
				error("povtor", 2, stacks, argv);
		}
		if (stacks->stack_a->size != (stacks->stack_a->head->prev->index + 1))
			stacks->flag_sort = 0;
		if (stacks->stack_a->head->prev->index == 0)
			stacks->stack_a->head_index = stacks->stack_a->head->prev;
	}
}
