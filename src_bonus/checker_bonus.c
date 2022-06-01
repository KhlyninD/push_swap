/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:55:09 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/21 13:13:02 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

static void	init_stacks(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->str = NULL;
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

static int	sorted(t_stack *stack_a)
{
	t_stack_elem	*el;
	int				i;

	el = stack_a->head;
	i = 0;
	while (i < (stack_a->size - 1))
	{
		if (el->value > el->next->value)
			return (1);
		el = el->next;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*str;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		str = ft_strjoin("!push_swap ", argv[1]);
		argv = ft_split(str, ' ');
		free(str);
		argc = splited_size(argv);
	}
	init_stacks(&stacks);
	lst_init_a(argv, &stacks);
	if (argv && argv[0][0] == '!')
		free_after_split(argv);
	if ((argc - 1) != stacks.stack_a->size)
		error("bad malloc el_new", 3, &stacks, NULL);
	read_stdin(&stacks);
	if (((argc - 1) != stacks.stack_a->size) || sorted(stacks.stack_a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	free_stacks(&stacks);
	return (0);
}
