/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:49:50 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/07 13:49:54 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;
	t_list	*k;

	if (!lst)
		return ;
	t = *lst;
	while (t)
	{
		k = t;
		t = t->next;
		del(k->content);
		free(k);
		k = NULL;
	}
	*lst = t;
}
