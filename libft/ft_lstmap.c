/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:48:30 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/07 13:48:35 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*t;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		t = ft_lstnew(f(lst->content));
		if (t)
		{
			ft_lstadd_back(&new, t);
			lst = lst->next;
		}
		else
		{
			while (new)
			{
				t = new->next;
				del(new->content);
				free(new);
				new = t;
			}
			return (NULL);
		}
	}
	return (new);
}
