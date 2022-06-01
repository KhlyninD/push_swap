/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:49:05 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/07 13:49:09 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (!lst)
		return ;
	l = *lst;
	if (l)
	{
		l = ft_lstlast(l);
		l->next = new;
	}
	else
		*lst = new;
}
