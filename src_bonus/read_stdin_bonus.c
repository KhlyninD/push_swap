/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:26:46 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/21 13:12:56 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

static void	check_str3(t_stacks *stacks)
{
	if (ft_strcmp(stacks->str, "rra") == 0)
		stacks->stack_a->head = stacks->stack_a->head->prev;
	else if (ft_strcmp(stacks->str, "rrb") == 0)
	{
		if (stacks->stack_b->size != 0)
			stacks->stack_b->head = stacks->stack_b->head->prev;
	}
	else if (ft_strcmp(stacks->str, "rrr") == 0)
	{
		stacks->stack_a->head = stacks->stack_a->head->prev;
		if (stacks->stack_b->size != 0)
			stacks->stack_b->head = stacks->stack_b->head->prev;
	}
	else
		error("bad rx/rrx/sx", 3, stacks, NULL);
}

static void	check_str2(t_stacks *stacks)
{
	if (ft_strcmp(stacks->str, "pa") == 0)
	{
		if (stacks->stack_b->size != 0)
			px(stacks->stack_b, stacks->stack_a);
	}
	else if (ft_strcmp(stacks->str, "pb") == 0)
	{
		if (stacks->stack_a->size != 0)
			px(stacks->stack_a, stacks->stack_b);
	}
	else if (ft_strcmp(stacks->str, "ra") == 0)
		stacks->stack_a->head = stacks->stack_a->head->next;
	else if (ft_strcmp(stacks->str, "rb") == 0)
	{
		if (stacks->stack_b->size != 0)
			stacks->stack_b->head = stacks->stack_b->head->next;
	}
	else if (ft_strcmp(stacks->str, "rr") == 0)
	{
		stacks->stack_a->head = stacks->stack_a->head->next;
		if (stacks->stack_b->size != 0)
			stacks->stack_b->head = stacks->stack_b->head->next;
	}
	else
		check_str3(stacks);
}

static void	check_str(t_stacks *stacks)
{
	if (ft_strcmp(stacks->str, "sa") == 0)
	{
		if (stacks->stack_a->size > 1)
			swap(stacks->stack_a);
	}
	else if (ft_strcmp(stacks->str, "sb") == 0)
	{
		if (stacks->stack_b->size > 1)
			swap(stacks->stack_b);
	}
	else if (ft_strcmp(stacks->str, "ss") == 0)
	{
		if (stacks->stack_a->size > 1 && stacks->stack_b->size > 1)
		{
			swap(stacks->stack_a);
			swap(stacks->stack_b);
		}
	}
	else
		check_str2(stacks);
}

void	read_stdin(t_stacks *stacks)
{
	int		read;

	stacks->stack_b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stacks->stack_b)
		error("bad malloc stack_b", 3, stacks, NULL);
	read = 1;
	while (read)
	{
		stacks->str = NULL;
		read = get_next_line(0, &stacks->str);
		if (read < 0)
			error("bad read", 3, stacks, NULL);
		if (stacks->str)
		{
			check_str(stacks);
			free(stacks->str);
		}
	}
}
