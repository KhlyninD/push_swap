/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:55:07 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/21 12:47:24 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
}	t_stack;

typedef struct s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	char			*str;
}	t_stacks;

void			free_after_split(char **argv);
void			free_stacks(t_stacks *stacks);
void			error(char *str, int ex, t_stacks *stacks, char **argv);
void			lst_init_a(char **argv, t_stacks *stacks);
t_stack_elem	*el_new(int content);
void			lstadd_back(t_stack *stack, t_stack_elem *elem);
void			lstadd_front(t_stack *stack, t_stack_elem *elem);
void			px(t_stack *stack_from, t_stack *stack_to);
void			swap(t_stack *stack);
void			read_stdin(t_stacks *stacks);
int				get_next_line(int fd, char **line);

#endif