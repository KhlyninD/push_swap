/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:00:19 by mjhin             #+#    #+#             */
/*   Updated: 2022/02/07 12:36:54 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	else if (n > 0)
	{
		while ((unsigned char)s1[i] == (unsigned char)s2[i]
			&& s1[i] != '\0' && s2[i] != '\0' && i < n)
			i++;
		if (i == n)
			return (0);
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
		return (-1);
}
