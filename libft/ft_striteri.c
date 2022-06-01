/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:33:04 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/06 14:33:07 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	len_s;

	if (!s)
		return ;
	len_s = ft_strlen(s);
	i = 0;
	while (i < len_s)
	{
		f(i, &s[i]);
		i++;
	}
}
