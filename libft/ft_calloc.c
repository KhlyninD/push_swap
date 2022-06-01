/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:47:36 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/05 16:47:38 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	i;
	size_t	n;

	n = count * size;
	s = (void *)malloc(n);
	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
	return (s);
}
