/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:33:47 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/21 10:16:54 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_after_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
}

static void	lstclear(t_stack *stack)
{
	size_t			i;
	t_stack_elem	*current;
	t_stack_elem	*delete;

	i = 0;
	current = stack->head;
	while (i < stack->size)
	{
		delete = current;
		current = current->next;
		free(delete);
		i++;
	}
	free(stack);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks->stack_a)
		lstclear(stacks->stack_a);
	if (stacks->stack_b)
		lstclear(stacks->stack_b);
}

void	error(char *str, int ex, t_stacks *stacks, char **argv)
{
	(void)str;
	ft_putstr_fd("Error\n", 2);
	if (argv && argv[0][0] == '!')
		free_after_split(argv);
	free_stacks(stacks);
	exit(ex);
}
