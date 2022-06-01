/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:47:23 by mjhin             #+#    #+#             */
/*   Updated: 2021/10/05 16:47:24 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*s;
	unsigned int	i;

	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (*(str + i))
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
