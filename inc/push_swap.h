/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:34:04 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/21 13:17:27 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack_elem
{
	int					value;
	size_t				index;
	int					push_b;
	struct s_stack_elem	*prev;
	struct s_stack_elem	*next;
}						t_stack_elem;

typedef struct s_stack
{
	t_stack_elem	*head;
	size_t			size;
	t_stack_elem	*head_index;
	t_stack_elem	*head_pb;
}	t_stack;

typedef struct s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				flag_sort;
	size_t			many_pb;
	t_stack_elem	*el_a;
	t_stack_elem	*el_b;
	int				a_r_rr;
	int				b_r_rr;
	size_t			size_r_rr;
	size_t			ra;
	size_t			rra;
	size_t			rb;
	size_t			rrb;
	int				is_set;
}	t_stacks;

void			error(char *str, int ex, t_stacks *stacks, char **argv);
void			free_stacks(t_stacks *stacks);
void			free_after_split(char **argv);

void			lst_init_a(char **argv, t_stacks *stacks);
void			unique_num(t_stacks *stacks);
void			min_push_b(t_stacks *stacks);

t_stack_elem	*el_new(int content);
void			lstadd_back(t_stack *stack, t_stack_elem *elem);
void			swap(t_stack *stack);
void			px(t_stack *stack_from, t_stack *stack_to);
void			push_a(t_stacks *stacks);
void			rx_rrx(t_stacks *stacks);

#endif